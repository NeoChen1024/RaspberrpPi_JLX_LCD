#include "st75256_lvgl_impl.h"

void _st75256_lv_impl_rounder(lv_disp_drv_t *disp_drv, lv_area_t *area) {
    st75256_t *lcd = disp_drv->user_data;
    if(lcd->mode == ST75256_MONO) {
        area->y1 = (area->y1 / 8) * 8;
        area->y2 = (area->y2 / 8) * 8 + 7;
    }
    else {
        area->y1 = (area->y1 / 4) * 4;
        area->y2 = (area->y2 / 4) * 4 + 3;
    }
}

void _st75256_lv_impl_set_px(lv_disp_drv_t *disp_drv, uint8_t *buf, lv_coord_t buf_w, lv_coord_t x, lv_coord_t y, lv_color_t color, lv_opa_t opa) {
    st75256_t *lcd = disp_drv->user_data;

    uint16_t byte_index;
    uint8_t bit_index;

    if(lcd->mode == ST75256_MONO) {
        byte_index = x + (y / 8) * buf_w;
        bit_index = 7 - (y & 7);
        if(color.full) {
            buf[byte_index] |= 1U << bit_index;
        }
        else {
            buf[byte_index] &= ~(1U << bit_index);
        }
    }
    else {
        byte_index = x + (y / 4) * buf_w;
        bit_index = 6 - ((y & 3) * 2);

        buf[byte_index] &= ~(3U << bit_index);

        if(color.full) {
            buf[byte_index] |= (3U << bit_index);
        }
    }
}

void _st75256_lv_impl_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) {
    st75256_t *lcd = disp_drv->user_data;
    st75256_upload_data(lcd, (uint8_t *)color_p, area->x1, area->x2, area->y1, area->y2);
    lv_disp_flush_ready(disp_drv);
}
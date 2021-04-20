#include "st7302_lvgl_impl.h"

#include "config.h"

void _st7302_lv_impl_rounder(lv_disp_drv_t *disp_drv, lv_area_t *area) {
    st7302_t *lcd = disp_drv->user_data;
    area->x1 = (area->x1 / 2) * 2;
    area->x2 = (area->x2 / 2) * 2 + 1;

    area->y1 = (area->y1 / 12) * 12;
    area->y2 = (area->y2 / 12) * 12 + 11;
}

void _st7302_lv_impl_set_px(lv_disp_drv_t *disp_drv, uint8_t *buf, lv_coord_t buf_w, lv_coord_t x, lv_coord_t y, lv_color_t color, lv_opa_t opa) {
    st7302_t *lcd = disp_drv->user_data;

    uint16_t byte_index = (buf_w / 2 * 3) * (y / 12) + (x / 2) * 3 + ((y % 12) / 4);
    uint8_t bit_index = (3 - (y % 4)) * 2 + (x % 2);

    if(color.full) {
        buf[byte_index] |= 1U << bit_index;
    }
    else {
        buf[byte_index] &= ~(1U << bit_index);
    }
}

void _st7302_lv_impl_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) {
    st7302_t *lcd = disp_drv->user_data;

    uint8_t column_start = 20 + CONFIG_DISPLAY_OFFSET_X + area->y1 / 12;
    uint8_t column_end = 20 + CONFIG_DISPLAY_OFFSET_X + area->y2 / 12;
    uint8_t row_start = CONFIG_DISPLAY_OFFSET_Y + area->x1 / 2;
    uint8_t row_end = CONFIG_DISPLAY_OFFSET_Y + area->x2 / 2;

    st7302_upload(lcd, column_start, column_end, row_start, row_end, (uint8_t *)color_p);
    lv_disp_flush_ready(disp_drv);
}
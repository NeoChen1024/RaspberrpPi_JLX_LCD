#ifndef __ST75256_LVGL_IMPL_H
#define __ST75256_LVGL_IMPL_H

#include "st75256_lcd.h"

#include "lvgl.h"

void _st75256_lv_impl_rounder(lv_disp_drv_t *disp_drv, lv_area_t *area);
void _st75256_lv_impl_set_px(lv_disp_drv_t *disp_drv, uint8_t *buf, lv_coord_t buf_w, lv_coord_t x, lv_coord_t y, lv_color_t color, lv_opa_t opa);
void _st75256_lv_impl_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);

#endif
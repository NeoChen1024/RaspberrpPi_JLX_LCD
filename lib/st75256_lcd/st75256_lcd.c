#include "st75256_lcd.h"

uint8_t jlx_25664_init_sequence[] = {
    0x00, 0x30,
    0x00, 0x94,
    0x00, 0x31,
    0x01, 0xD7, 0x9F,
    0x03, 0x32, 0x00, 0x01, 0x03,
    0x10, 0x20, 0x01, 0x03, 0x05, 0x07, 0x09, 0x0B, 0x0D, 0x10, 0x11, 0x13, 0x15, 0x17, 0x19, 0x1B, 0x1D, 0x1F,
    0x00, 0x30,
    0x02, 0x75, 0x00, 0x14,
    0x02, 0x15, 0x00, 0xFF,
    0x02, 0xBC, 0x00, 0xA6,
    0x03, 0xCA, 0x00, 0x9F, 0x20,
    0x01, 0xF0, 0x10,
    0x02, 0x81, 0x36, 0x04,
    0x01, 0x20, 0x0B
};

st75256_ret_t _st75256_hardware_reset(st75256_t *lcd) {
    ST75256_ERROR_CHECK(lcd->cb.reset_cb(lcd->user_data));
    return ST75256_OK;
}

st75256_ret_t _st75256_init_seq(st75256_t *lcd) {
   uint16_t i = 0;
 
    while(i < sizeof(ST75256_PANEL_SELECTION)) {
        ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, &ST75256_PANEL_SELECTION[i + 1], ST75256_PANEL_SELECTION[i] + 1));
        i += ST75256_PANEL_SELECTION[i] + 2;
    }

    return ST75256_OK;
}

st75256_ret_t _st75256_display_on(st75256_t *lcd) {
    uint8_t cmd = 0xAF;
    ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, &cmd, 0x01));
}

st75256_ret_t st75256_init(st75256_t *lcd) {
    ST75256_ERROR_CHECK(_st75256_hardware_reset(lcd));
    ST75256_ERROR_CHECK(_st75256_init_seq(lcd));
    ST75256_ERROR_CHECK(lcd->cb.delay_cb(lcd->user_data, 200));
    ST75256_ERROR_CHECK(_st75256_display_on(lcd));

    return ST75256_OK;
}

st75256_ret_t st75256_set_contrast(st75256_t *lcd, uint16_t contrast) {
    uint8_t cmd[3] = { 0x81, contrast & 0x3F, (contrast >> 6U) & 0x07 };
    ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, cmd, 0x03));

    return ST75256_OK;
}

st75256_ret_t st75256_set_mode(st75256_t *lcd, st75256_mode_t mode) {
    uint8_t cmd[2] = { 0xF0, 0x10 };
    if(mode == ST75256_GREY) {
        cmd[1] |= 0x01;
    }

    ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, cmd, 0x02));

    lcd->mode = mode;

    return ST75256_OK;
}

st75256_ret_t st75256_cursor(st75256_t *lcd, uint8_t x_start, uint8_t x_end, uint8_t y_start, uint8_t y_end) {
    
}
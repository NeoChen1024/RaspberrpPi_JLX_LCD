#include "st75256_lcd.h"

uint8_t jlx_25664_init_sequence[] = {
    0x00, 0x30, // Extension command EXT[1:0] = 0,0
    0x00, 0x94, // Set power save mode, SLP = 0
    0x00, 0x31, // Extension command EXT[1:0] = 0,1
    0x01, 0xD7, 0x9F, // Set auto-read instruction, XARD = 1
    0x03, 0x32, 0x00, 0x01, 0x03, // 32 - Set analog circuit, BE[1:0] = 0,1; BS[2:0] = 0,1,1
    0x10, 0x20, 0x00, 0x00, 0x00, 0x0B, 0x0B, 0x0B, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x10, 0x10, 0x00, 0x00, // 31 - Set grey scale level
    0x04, 0xF0, 0x0D, 0x0D, 0x0D, 0x0D, // Frame rate, 0x0C - 69.0Hz
    0x00, 0x30, // Extension command EXT[1:0] = 0,0
    0x02, 0x75, 0x00, 0x14, // 7 - Set page address, YS = 0x00, YE = 0x14
    0x02, 0x15, 0x00, 0xFF, // 8 - Set column address, XS = 0x00, XE = 0xFF
    0x01, 0xBC, 0x00, // 9 - Data scan direction, MV = 0, MX = 0, MY = 0
    0x03, 0xCA, 0x00, 0x9F, 0x20, // 5 - Display control, CLD = 0(not divide), DT = 0x9F(128), LF[4:0] = 1,0,0,0,0(16); FL = 0
    0x01, 0xF0, 0x10, // 28 - Display mode: DM = 0(Mono)
    0x02, 0x81, 0x36, 0x04, // 21 - Set VOP, VOP = 0x136
    0x01, 0x20, 0x0B // 20 - Power control, VB = 1, VF = 1, VR = 1
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
    uint8_t cmd = 0x30; 
    ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, &cmd, 0x01));

    cmd = 0xAF;
    ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, &cmd, 0x01));

    return ST75256_OK;
}

st75256_ret_t _st75256_cursor(st75256_t *lcd, uint8_t column_start, uint8_t column_end, uint8_t page_start, uint8_t page_end) {
    uint8_t cmd[] = { 0x30, 0x15, column_start, column_end, 0x75, page_start, page_end };
    ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, cmd, 0x01)); // Extension command EXT[1:0] = 0,0
    ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, &cmd[1], 0x03));
    ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, &cmd[4], 0x03));
    return ST75256_OK;
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

st75256_ret_t st75256_upload_data(st75256_t *lcd, uint8_t *data, uint8_t x_start, uint8_t x_end, uint8_t y_start, uint8_t y_end) {
    uint8_t cmd = 0x30;
    ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, &cmd, 0x01)); // Ext. Command 1

    uint32_t bytes_to_transfer = 0x00;
    uint8_t page_offset = (lcd->mode == ST75256_GREY ? 8 : 4);
    uint8_t page_start = page_offset;
    uint8_t page_end = page_offset;

    if(lcd->mode == ST75256_GREY) {
        if(y_start % 4 != 0 || (y_end + 1) % 4 != 0) {
            return ST75256_ERROR;
        }
        bytes_to_transfer = (x_end - x_start + 1) * (y_end - y_start + 1) / 4;
        page_start += y_start / 4;
        page_end += y_end / 4;
    }
    else {
        if(y_start % 8 != 0 || (y_end + 1) % 8 != 0) {
            return ST75256_ERROR;
        }
        bytes_to_transfer = (x_end - x_start + 1) * (y_end - y_start + 1) / 8;
        page_start += y_start / 8;
        page_end += y_end / 8;
    }

    ST75256_ERROR_CHECK(_st75256_cursor(lcd, x_start, x_end, page_start, page_end));

    cmd = 0x5C;
    ST75256_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, &cmd, 0x01)); // Write data
    ST75256_ERROR_CHECK(lcd->cb.write_data_cb(lcd->user_data, data, (uint16_t)bytes_to_transfer));

    return ST75256_OK;
}
#include "st7302_lcd.h"

uint8_t st7302_gd_unknown_init_sequence[] = {
    0x01, 0xEB, 0x02, // Enable OTP
    0x01, 0xD7, 0x68, // OTP Load Control
    0x01, 0xD1, 0x01, // Auto Power Control
    0x01, 0xC0, 0x40, // Gate Voltage setting
    0x06, 0xC1, 0x22, 0x28, 0x28, 0x22, 0x14, 0x00, // VSH Setting
    0x04, 0xC2, 0x00, 0x00, 0x00, 0x00, // VSL Setting
    0x01, 0xCB, 0x0E, // VCOMH Setting
    0x01, 0xB3, 0x94, // VCOM EQ Enable
    0x0A, 0xB4, 0xE5, 0x66, 0x85, 0xFF, 0xFF, 0x52, 0x85, 0xFF, 0xFF, 0x52, // Gate EQ
    0x02, 0xC7, 0xA6, 0xE9, // OSC Setting
    0x01, 0xB0, 0x3F, // Duty Setting
    0x02, 0xB2, 0x01, 0x05, // Frame Rate Setting
    0x01, 0x36, 0x20, // Memory Access Mode
    0x01, 0x3A, 0x01, // Data Format
    0x01, 0xB9, 0x23, // Source Setting
    0x01, 0xB8, 0x09, // Panel Setting
    0x02, 0x2A, 0x19, 0x23, // Column Address Setting
    0x02, 0x2B, 0x00, 0x7C, // Row Address Setting
};

uint8_t st7302_gd_unknown_hpm_init_sequence[] = {
    0x01, 0xEB, 0x02, // Enable OTP
    0x01, 0xD7, 0x68, // OTP Load Control
    0x01, 0xD1, 0x01, // Auto Power Control
    0x01, 0xC0, 0xF6, // Gate Voltage setting
    0x06, 0xC1, 0x28, 0x28, 0x28, 0x28, 0x14, 0x00, // VSH Setting
    0x04, 0xC2, 0x06, 0x06, 0x06, 0x06, // VSL Setting
    0x01, 0xCB, 0x08, // VCOMH Setting
    0x01, 0xB3, 0x94, // VCOM EQ Enable
    0x0A, 0xB4, 0xE5, 0x66, 0xFD, 0xFF, 0xFF, 0x7F, 0xFD, 0xFF, 0xFF, 0x7F, // Gate EQ
    0x02, 0xC7, 0xA6, 0xE9, // OSC Setting
    0x01, 0xB0, 0x3F, // Duty Setting
    0x02, 0xB2, 0x00, 0x05, // Frame Rate Setting
    0x01, 0x36, 0x20, // Memory Access Mode
    0x01, 0x3A, 0x01, // Data Format
    0x01, 0xB9, 0x23, // Source Setting
    0x01, 0xB8, 0x09, // Panel Setting
    0x02, 0x2A, 0x19, 0x23, // Column Address Setting
    0x02, 0x2B, 0x00, 0x7C, // Row Address Setting
};

st7302_ret_t _st7302_init_seq(st7302_t *lcd) {
    uint16_t i = 0;
    
    while(i < sizeof(ST7302_PANEL_SELECTION)) {
        ST7302_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, &ST7302_PANEL_SELECTION[i + 1], ST7302_PANEL_SELECTION[i] + 1));
        i += ST7302_PANEL_SELECTION[i] + 2;
    }

    return ST7302_OK;
}

st7302_ret_t st7302_init(st7302_t *lcd) {
    ST7302_ERROR_CHECK(lcd->cb.reset_cb(lcd->user_data));

    ST7302_ERROR_CHECK(_st7302_init_seq(lcd));
    uint8_t command[3] = {0xB2, 0x01, 0x05};
    command[0] = 0x11;
    ST7302_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, command, 0x01)); // Sleep Out
    ST7302_ERROR_CHECK(lcd->cb.delay_cb(lcd->user_data, 100 * 1000));
    command[0] = 0x29;
    ST7302_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, command, 0x01)); // Display ON

    command[0] = 0x39;
    ST7302_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, command, 0x01)); // LPM ON

    return ST7302_OK;
}

st7302_ret_t st7302_upload(st7302_t *lcd, uint8_t col_start, uint8_t col_end, uint8_t row_start, uint8_t row_end, uint8_t *data) {
    uint8_t command[3] = { 0x2A, col_start, col_end };
    ST7302_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, command, 0x03)); // Column address set

    command[0] = 0x2B;
    command[1] = row_start;
    command[2] = row_end;
    ST7302_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, command, 0x03)); // Row address set

    command[0] = 0x2C; // Write DATA
    ST7302_ERROR_CHECK(lcd->cb.write_cmd_cb(lcd->user_data, command, 0x01));

    uint16_t data_len = (col_end - col_start + 1) * (row_end - row_start + 1) * 3;

    ST7302_ERROR_CHECK(lcd->cb.write_data_cb(lcd->user_data, data, data_len));
}

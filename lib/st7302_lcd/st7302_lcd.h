#ifndef __ST7302_LCD_H
#define __ST7302_LCD_H

#include <stdint.h>

#define ST7302_PANEL_SELECTION st7302_gd_unknown_init_sequence

typedef enum {
    ST7302_OK,
    ST7302_ERROR
} st7302_ret_t;

typedef struct {
    st7302_ret_t (*reset_cb)(void *handle);
    st7302_ret_t (*delay_cb)(void *handle, uint32_t usec);
    st7302_ret_t (*write_cmd_cb)(void *handle, uint8_t *cmd, uint8_t len);
    st7302_ret_t (*write_data_cb)(void *handle, uint8_t *data, uint16_t len);
} st7302_cb_t;

typedef struct {
    void *user_data;
    st7302_cb_t cb;
} st7302_t;

#define ST7302_ERROR_CHECK(x) if(x != ST7302_OK) return ST7302_ERROR

st7302_ret_t st7302_init(st7302_t *lcd);
st7302_ret_t st7302_upload(st7302_t *lcd, uint8_t col_start, uint8_t col_end, uint8_t row_start, uint8_t row_end, uint8_t *data);

#endif
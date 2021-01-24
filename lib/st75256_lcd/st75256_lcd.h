#ifndef __ST75256_LCD_H
#define __ST75256_LCD_H

#include <stdint.h>

#define ST75256_PANEL_SELECTION jlx_25664_init_sequence

typedef enum {
    ST75256_OK,
    ST75256_ERROR
} st75256_ret_t;

typedef enum {
    ST75256_MONO,
    ST75256_GREY
} st75256_mode_t;

typedef struct {
    st75256_ret_t (*write_cmd_cb)(void *handle, uint8_t *cmd, uint8_t len);
    st75256_ret_t (*write_data_cb)(void *handle, uint8_t *data, uint16_t len);
    st75256_ret_t (*reset_cb)(void *handle);
    st75256_ret_t (*delay_cb)(void *handle, uint32_t usec);
} st75256_cb_t;

typedef struct {
    void *user_data;
    st75256_cb_t cb;
    st75256_mode_t mode;
} st75256_t;

#define ST75256_ERROR_CHECK(x) if(x != ST75256_OK) return ST75256_OK

st75256_ret_t st75256_init(st75256_t *lcd);
st75256_ret_t st75256_set_contrast(st75256_t *lcd, uint16_t contrast);
st75256_ret_t st75256_set_mode(st75256_t *lcd, st75256_mode_t mode);
st75256_ret_t st75256_upload_data(st75256_t *lcd, uint8_t *data, uint8_t x_start, uint8_t x_end, uint8_t y_start, uint8_t y_end);

#endif
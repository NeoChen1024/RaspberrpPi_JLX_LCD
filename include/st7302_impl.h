#ifndef __ST7302_IMPL_H
#define __ST7302_IMPL_H

// SPIDEV
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

// LIBGPIOD
#include <gpiod.h>

// USER
#include "st7302_lcd.h"
#include "config.h"

typedef struct {
    int spi_fd;
    struct gpiod_chip *gpio_chip;
    struct gpiod_line *gpio_line_res;
    struct gpiod_line *gpio_line_dc;
} _st7302_impl_t;

_st7302_impl_t *_st7302_impl_init(void);
int _st7302_impl_deinit(_st7302_impl_t *handle);
st7302_ret_t _st7302_impl_write_cmd(void *handle, uint8_t *cmd, uint8_t len);
st7302_ret_t _st7302_impl_write_data(void *handle, uint8_t *data, uint16_t len);
st7302_ret_t _st7302_impl_reset(void *handle);
st7302_ret_t _st7302_impl_delay(void *handle, uint32_t usec);

#endif
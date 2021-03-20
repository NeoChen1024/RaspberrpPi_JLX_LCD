#include "st7302_impl.h"

#define SPIDEV_MAX_LEN 4096

_st7302_impl_t *_st7302_impl_init(void) {
    int spi_fd = open(CONFIG_SPIDEV_FILENAME, O_RDWR | O_SYNC);
    if(spi_fd < 0) return NULL;

    uint32_t spi_mode = 0; // Nothing to be set in default mode.

    int ret = ioctl(spi_fd, SPI_IOC_WR_MODE32, &spi_mode);
    if(ret == -1) goto spi_err_out;

    ret = ioctl(spi_fd, SPI_IOC_RD_MODE32, &spi_mode);
    if(ret == -1) goto spi_err_out;

    uint32_t spi_word_len = 8;

    ret= ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &spi_word_len);
    if(ret == -1) goto spi_err_out;

    ret = ioctl(spi_fd, SPI_IOC_RD_BITS_PER_WORD, &spi_word_len);
    if(ret == -1) goto spi_err_out;

    uint32_t spi_speed = 16000000; // 16MHz

    ret = ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &spi_speed);
    if(ret == -1) goto spi_err_out;

    ret = ioctl(spi_fd, SPI_IOC_RD_MAX_SPEED_HZ, &spi_speed);
    if(ret == -1) goto spi_err_out;

    _st7302_impl_t *impl = malloc(sizeof(_st7302_impl_t));
    if(impl == NULL) goto spi_err_out;

    impl->spi_fd = spi_fd;

    impl->gpio_chip = gpiod_chip_open(CONFIG_GPIO_CHIP);
    if(impl->gpio_chip == NULL) goto impl_err_out;

    impl->gpio_line_res = gpiod_chip_get_line(impl->gpio_chip, CONFIG_RES_PIN);
    if(impl->gpio_line_res == NULL) goto gpiod_err_out;

    impl->gpio_line_dc = gpiod_chip_get_line(impl->gpio_chip, CONFIG_DC_PIN);
    if(impl->gpio_line_dc == NULL) goto gpiod_err_out;

    ret = gpiod_line_request_output(impl->gpio_line_dc, CONFIG_GPIO_CONSUMER, 1);
    if(ret != 0) goto gpiod_err_out;
    
    ret = gpiod_line_request_output(impl->gpio_line_res, CONFIG_GPIO_CONSUMER, 1);
    if(ret != 0) goto gpiod_err_out;

    return impl;

gpiod_err_out:
    gpiod_chip_close(impl->gpio_chip);

impl_err_out:
    free(impl);

spi_err_out:
    close(spi_fd);
    return NULL;
}

int _st7302_impl_deinit(_st7302_impl_t *handle) {
    close(handle->spi_fd);
    gpiod_chip_close(handle->gpio_chip);
    free(handle);
    return 0;
}

st7302_ret_t _st7302_impl_write_cmd(void *handle, uint8_t *cmd, uint8_t len) {
    _st7302_impl_t *impl = handle;

    int ret = gpiod_line_set_value(impl->gpio_line_dc, 0);
    if(ret) return ST7302_ERROR;

    struct spi_ioc_transfer cmd_tr = {
        .tx_buf = (unsigned long)cmd,
        .rx_buf = (unsigned long)NULL,
        .len = 1,
        .bits_per_word = 8
    };

    ret = ioctl(impl->spi_fd, SPI_IOC_MESSAGE(1), &cmd_tr);
    if(ret < 1) return ST7302_ERROR;

    if(len > 1) {
        ret = gpiod_line_set_value(impl->gpio_line_dc, 1); // Set DC pin
        if(ret) return ST7302_ERROR;
        cmd_tr.tx_buf = (unsigned long)&cmd[1]; //2nd transfer
        cmd_tr.len = len - 1;

        ret = ioctl(impl->spi_fd, SPI_IOC_MESSAGE(1), &cmd_tr);
        if(ret < len - 1) return ST7302_ERROR;
    }

    return ST7302_OK;
}

st7302_ret_t _st7302_impl_write_data(void *handle, uint8_t *data, uint16_t len) {
    _st7302_impl_t *impl = handle;

    int ret = gpiod_line_set_value(impl->gpio_line_dc, 1);

    struct spi_ioc_transfer data_tr = {
        .tx_buf = (unsigned long)data,
        .rx_buf = (unsigned long)NULL,
        .len = len,
        .bits_per_word = 8
    };

    uint32_t transfer_times = (len / SPIDEV_MAX_LEN) + ((len % SPIDEV_MAX_LEN != 0) ? 1 : 0); // Linux SPI can transfer some bytes each time.
    for(uint32_t i = 0; i < transfer_times; i++) {
        if(i == transfer_times - 1) {
            data_tr.len = len - SPIDEV_MAX_LEN * i;
        }
        else {
            data_tr.len = SPIDEV_MAX_LEN;
        }

        data_tr.tx_buf = (unsigned long)(&data[SPIDEV_MAX_LEN * i]);

        ret = ioctl(impl->spi_fd, SPI_IOC_MESSAGE(1), &data_tr);
        if(ret < data_tr.len) return ST7302_ERROR;
    }

    return ST7302_OK;
}

st7302_ret_t _st7302_impl_reset(void *handle) {
    _st7302_impl_t *impl = handle;

    usleep(10 * 1000);

    int ret = gpiod_line_set_value(impl->gpio_line_res, 0);
    if(ret) return ST7302_ERROR;

    usleep(10 * 1000);

    ret = gpiod_line_set_value(impl->gpio_line_res, 1);
    if(ret) return ST7302_ERROR;

    usleep(10 * 1000);

    return ST7302_OK;
}

st7302_ret_t _st7302_impl_delay(void *handle, uint32_t usec) {
    usleep(usec);
    return ST7302_OK;
}
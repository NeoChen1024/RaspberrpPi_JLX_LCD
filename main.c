#include <stdio.h>

#include "st75256_lcd.h"
#include "st75256_impl.h"
#include "user_tasks.h"

st75256_t g_lcd = {
    .user_data = NULL,
    .cb = {
        .write_cmd_cb = _lcd_impl_write_cmd,
        .write_data_cb = _lcd_impl_write_data,
        .reset_cb = _lcd_impl_reset,
        .delay_cb = _lcd_impl_delay
    }
};

int main() {
    g_lcd.user_data = _lcd_impl_init();
    if(g_lcd.user_data == NULL) return -1;

    st75256_init(&g_lcd);
    st75256_set_contrast(&g_lcd, 305);
    st75256_set_mode(&g_lcd, ST75256_GREY);

    user_tasks_init();
    user_tasks_loop();
    user_tasks_deinit();

    printf("Hello World!!\n");
    return 0;
}
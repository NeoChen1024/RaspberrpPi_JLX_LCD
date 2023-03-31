
#include <stdint.h>
#include <unistd.h>

#include "lvgl.h"

#include "st7302_impl.h"
#include "st7302_lvgl_impl.h"

#include "user_tasks.h"

pthread_mutex_t g_lvgl_mutex = PTHREAD_MUTEX_INITIALIZER;

st7302_t g_lcd = {
    .user_data = NULL,
    .cb = {
        .write_cmd_cb = _st7302_impl_write_cmd,
        .write_data_cb = _st7302_impl_write_data,
        .reset_cb = _st7302_impl_reset,
        .delay_cb = _st7302_impl_delay
    }
};

#define LCD_BUF_SIZE (250 * 24)

lv_disp_buf_t g_lcd_disp_buf;
lv_color_t g_lcd_buf[LCD_BUF_SIZE];

int lvgl_task_init(void) {
    int ret;

    g_lcd.user_data = _st7302_impl_init();
    if(g_lcd.user_data == NULL) return -1;

    st7302_init(&g_lcd);

    lv_init();

    lv_disp_buf_init(&g_lcd_disp_buf, g_lcd_buf, NULL, LCD_BUF_SIZE);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.buffer = &g_lcd_disp_buf;
    disp_drv.set_px_cb = _st7302_lv_impl_set_px;
    disp_drv.flush_cb = _st7302_lv_impl_flush;
    disp_drv.rounder_cb = _st7302_lv_impl_rounder;
    disp_drv.user_data = &g_lcd;

    lv_disp_drv_register(&disp_drv);

    ret = pthread_create(&lvgl_tick_thread_handle, NULL, lvgl_tick_thread, NULL);
    if(ret) return ret;
    ret = pthread_create(&lvgl_task_thread_handle, NULL, lvgl_task_thread, NULL);
    if(ret) return ret;
    ret = pthread_setname_np(lvgl_task_thread_handle, "LV_TASK");
    ret = pthread_setname_np(lvgl_tick_thread_handle, "LV_TICK");
}

int lvgl_task_deinit(void) {
    pthread_join(lvgl_task_thread_handle, NULL);
    pthread_join(lvgl_tick_thread_handle, NULL);
}

pthread_t lvgl_tick_thread_handle;
void *lvgl_tick_thread(void *arguments) {
    while(g_running) {
        usleep(29 * 1000);
        pthread_mutex_lock(&g_lvgl_mutex);
        lv_tick_inc(30);
        pthread_mutex_unlock(&g_lvgl_mutex);
    }
}

pthread_t lvgl_task_thread_handle;
void *lvgl_task_thread(void *arguments) {
    while(g_running) {
        usleep(17 * 1000);
        pthread_mutex_lock(&g_lvgl_mutex);
        lv_task_handler();
        pthread_mutex_unlock(&g_lvgl_mutex);
    }
}
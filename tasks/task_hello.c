#include <stdio.h>

#include <time.h>
#include <stdint.h>
#include <unistd.h>

#include "lvgl.h"

#include "user_tasks.h"

extern uint8_t g_running;
extern pthread_mutex_t g_lvgl_mutex;

int hello_task_init(void) {
    int ret = pthread_create(&hello_thread_handle, NULL, hello_thread, NULL);
    ret = pthread_setname_np(hello_thread_handle, "HELLO_THR");
}

int hello_task_deinit(void) {

}

pthread_t hello_thread_handle;
void *hello_thread(void *arguments) {
    pthread_mutex_lock(&g_lvgl_mutex);

    lv_style_t hello_label_style;
    lv_style_init(&hello_label_style);
    lv_style_set_text_font(&hello_label_style, LV_STATE_DEFAULT, &lv_font_unscii_8);

    lv_obj_t *hello_label = lv_label_create(lv_scr_act(), NULL);
    lv_obj_set_width(hello_label, 200);
    lv_label_set_text(hello_label, "----/--/-- --:--:-- N/A");
    lv_obj_add_style(hello_label, LV_LABEL_PART_MAIN, &hello_label_style);
    lv_label_set_long_mode(hello_label, LV_LABEL_LONG_SROLL_CIRC);
    lv_obj_align(hello_label, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

    pthread_mutex_unlock(&g_lvgl_mutex);

    tzset();

    time_t cur_time;
    struct tm *time_info;

    char date_buf[25];

    while(g_running) {
        time(&cur_time);
        time_info = localtime(&cur_time); // Note: THIS IS NTS

        snprintf(date_buf, 25, "%04d/%02d/%02d %02d:%02d:%02d %s",
            time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday,
            time_info->tm_hour, time_info->tm_min, time_info->tm_sec, tzname[0]
        );

        pthread_mutex_lock(&g_lvgl_mutex);

        lv_label_set_text(hello_label, date_buf);
        lv_obj_align(hello_label, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

        pthread_mutex_unlock(&g_lvgl_mutex);
        usleep(100 * 1000);
    }
}

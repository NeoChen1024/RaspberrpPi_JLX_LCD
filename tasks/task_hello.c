#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>

#include "lvgl.h"

#include "user_tasks.h"

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
    lv_style_set_text_font(&hello_label_style, LV_STATE_DEFAULT, &unica_one_12);

    lv_obj_t *hello_label = lv_label_create(lv_scr_act(), NULL);
    lv_obj_set_width(hello_label, 320);
    lv_label_set_text(hello_label, "XXXX-XX-XXTXX:XX:XX+XXXX");
    lv_obj_add_style(hello_label, LV_LABEL_PART_MAIN, &hello_label_style);
    //lv_label_set_long_mode(hello_label, LV_LABEL_LONG_SROLL_CIRC);
    lv_obj_align(hello_label, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

    pthread_mutex_unlock(&g_lvgl_mutex);

    tzset();

    while(g_running) {
        time_t cur_time;        
        char date_buf[25];

        struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);
        ts.tv_sec++; // Increment to the next second
        ts.tv_nsec = 0; // Set nanoseconds to 0 to start at the beginning of the second

        cur_time = time(NULL) + 1; // Increment to the next second
        struct tm *time_info = localtime(&cur_time); // Note: THIS IS NTS

        strftime(date_buf, 25, "%Y-%m-%dT%H:%M:%S%z", time_info);

        pthread_mutex_lock(&g_lvgl_mutex);

        lv_label_set_text(hello_label, date_buf);
        lv_obj_align(hello_label, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

        pthread_mutex_unlock(&g_lvgl_mutex);

        clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &ts, NULL); // Sleep until the start of the next second
    }
}

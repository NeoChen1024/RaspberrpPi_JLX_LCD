#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#include "lvgl.h"

#include "user_tasks.h"

extern uint8_t g_running;
extern pthread_mutex_t g_lvgl_mutex;

int load_task_init(void) {
    int ret = pthread_create(&load_thread_handle, NULL, load_thread, NULL);
    ret = pthread_setname_np(load_thread_handle, "LOAD_THR");
}

int load_task_deinit(void) {

}

pthread_t load_thread_handle;
void *load_thread(void *arguments) {
    pthread_mutex_lock(&g_lvgl_mutex);
    lv_style_t load_label_style;
    lv_style_init(&load_label_style);
    lv_style_set_text_font(&load_label_style, LV_STATE_DEFAULT, &lv_font_unscii_8);

    lv_obj_t *load_label = lv_label_create(lv_scr_act(), NULL);
    lv_obj_set_width(load_label, 150);
    lv_label_set_text(load_label, "LOAD AVG. --.--/--.--/--.--");
    lv_obj_add_style(load_label, LV_LABEL_PART_MAIN, &load_label_style);
    lv_obj_align(load_label, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 8);

    pthread_mutex_unlock(&g_lvgl_mutex);

    double load_avg[3];
    char load_buf[28];

    while(g_running) {
        getloadavg(load_avg, 3);

        snprintf(load_buf, 28, "LOAD AVG. %02.02f/%02.02f/%02.02f",
            load_avg[0], load_avg[1], load_avg[2]
        );
        pthread_mutex_lock(&g_lvgl_mutex);

        lv_label_set_text(load_label, load_buf);
        lv_obj_align(load_label, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 8);
        pthread_mutex_unlock(&g_lvgl_mutex);
        sleep(1);
    }
}

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
    lv_style_set_text_font(&hello_label_style, LV_STATE_DEFAULT, &jf_dot_jiskan24_2000);

    lv_obj_t * hello_label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(hello_label, LV_LABEL_LONG_SROLL_CIRC);     /*Circular scroll*/
    lv_label_set_anim_speed(hello_label, 1);
    lv_obj_set_width(hello_label, 250);
    lv_label_set_text(hello_label, "JFドットjiskan24-2000 電子情報技術産業協会 / 矢木達也氏");
    lv_obj_add_style(hello_label, LV_LABEL_PART_MAIN, &hello_label_style);
    lv_obj_align(hello_label, NULL, LV_ALIGN_CENTER, 0, 0);

    pthread_mutex_unlock(&g_lvgl_mutex);
    while(g_running) {
        sleep(1);
    }
}
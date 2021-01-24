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
    lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(label2, LV_LABEL_LONG_SROLL_CIRC);     /*Circular scroll*/
    lv_label_set_anim_speed(label2, 3);
    lv_obj_set_width(label2, 256);
    lv_label_set_text(label2, "It is a circularly scrolling text. ");
    lv_obj_align(label2, NULL, LV_ALIGN_IN_TOP_MID, 0, 30);
    pthread_mutex_unlock(&g_lvgl_mutex);
    while(g_running) {
        sleep(1);
    }
}
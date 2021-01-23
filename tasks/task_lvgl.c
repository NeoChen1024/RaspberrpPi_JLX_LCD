
#include <stdint.h>
#include <unistd.h>

#include "lvgl.h"

#include "user_tasks.h"

extern uint8_t g_running;

pthread_mutex_t g_lvgl_mutex = PTHREAD_MUTEX_INITIALIZER;

int lvgl_task_init(void) {
    int ret;
    lv_init();
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
        usleep(30 * 1000);
        pthread_mutex_lock(&g_lvgl_mutex);
        lv_tick_inc(30);
        pthread_mutex_unlock(&g_lvgl_mutex);
    }
}

pthread_t lvgl_task_thread_handle;
void *lvgl_task_thread(void *arguments) {
    while(g_running) {
        usleep(10 * 1000);
        pthread_mutex_lock(&g_lvgl_mutex);
        lv_task_handler();
        pthread_mutex_unlock(&g_lvgl_mutex);
    }
}
#ifndef __USER_TASKS_H
#define __USER_TASKS_H

#include <pthread.h>
#include <stdint.h>

extern volatile uint8_t g_running;
extern pthread_mutex_t g_lvgl_mutex;

void user_tasks_init(void);
void user_tasks_loop(void);
void user_tasks_deinit(void);

int lvgl_task_init(void);
int lvgl_task_deinit(void);
extern pthread_t lvgl_tick_thread_handle;
void *lvgl_tick_thread(void *arguments);
extern pthread_t lvgl_task_thread_handle;
void *lvgl_task_thread(void *arguments);

int hello_task_init(void);
int hello_task_deinit(void);
extern pthread_t hello_thread_handle;
void *hello_thread(void *arguments);

int load_task_init(void);
int load_task_deinit(void);
extern pthread_t load_thread_handle;
void *load_thread(void *arguments);

#endif
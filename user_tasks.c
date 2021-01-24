#include <stdint.h>
#include <signal.h>
#include <unistd.h>

#include "user_tasks.h"

uint8_t g_running = 1;

void _user_signal_handler(int signo) {
    if(signo == SIGINT) {
        g_running = 0;
    }
}

void user_tasks_init(void) {

    if(signal(SIGINT, _user_signal_handler) == SIG_ERR) {
        return;
    }

    lvgl_task_init();
    hello_task_init();
}

void user_tasks_loop(void) {
    while(g_running) {
        sleep(1);
    }
}

void user_tasks_deinit(void) {
    hello_task_deinit();
    lvgl_task_deinit();
}
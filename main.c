#include <stdio.h>
#include <string.h>

#include "user_tasks.h"

int main() {
    user_tasks_init();
    user_tasks_loop();
    user_tasks_deinit();

    printf("Hello World!!\n");
    return 0;
}
cmake_minimum_required(VERSION 3.12)

project(lcd_jlx C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
    "main.c"
    "st75256_impl.c"
    "st7302_impl.c"
    "st75256_lvgl_impl.c"
    "st7302_lvgl_impl.c"
    "user_tasks.c"
    "fonts/jf_dot_jiskan24_2000.c"
    "fonts/jf_dot_jiskan16.c"
    "fonts/unica_one_12.c"
    "images/pixiv_87209173.c"
    "tasks/task_lvgl.c"
    "tasks/task_hello.c"
    "tasks/task_load.c"
    "lib/st75256_lcd/st75256_lcd.c"
    "lib/st7302_lcd/st7302_lcd.c"
)

set(C_INCLUDES
    "include"
    "lib/st75256_lcd"
    "lib/st7302_lcd"
    "lib/LittleVGL"
)

set(C_DEFINES
    "_GNU_SOURCE"
    "LV_LVGL_H_INCLUDE_SIMPLE"
)

set(C_LIBRARIES
    "gpiod"
    "pthread"
    "st7302"
    "lvgl"
)

set(LVGL_DEFINES
    "LV_CONF_INCLUDE_SIMPLE"
)

add_subdirectory(lib)

add_executable(lcd_jlx ${SOURCES})
target_link_libraries(lcd_jlx ${C_LIBRARIES})
target_include_directories(lcd_jlx PRIVATE ${C_INCLUDES})
target_compile_definitions(lcd_jlx PRIVATE ${C_DEFINES})
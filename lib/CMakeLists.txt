 
# Note: LittleVGL officially supports Zephyr and ESP-IDF, we are neither.
file(GLOB_RECURSE LVGL_SOURCES 
    "LittleVGL/src/*.c"
)

set(LVGL_INCLUDES
    "../include"
)

add_library(lvgl STATIC ${LVGL_SOURCES})
target_include_directories(lvgl PRIVATE ${LVGL_INCLUDES})
target_compile_definitions(lvgl PRIVATE ${LVGL_DEFINES})


set(ST7302_LCD_SOURCES
    "st7302_lcd/st7302_lcd.c"
)

add_library(st7302 STATIC ${ST7302_LCD_SOURCES})

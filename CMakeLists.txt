cmake_minimum_required(VERSION 3.12)

project(lcd_jlx C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
    main.c
    st75256_impl.c
    user_tasks.c
    tasks/task_lvgl.c
    lib/st75256_lcd/st75256_lcd.c
    lib/LittleVGL/src/lv_themes/lv_theme.c
    lib/LittleVGL/src/lv_themes/lv_theme_empty.c
    lib/LittleVGL/src/lv_themes/lv_theme_material.c
    lib/LittleVGL/src/lv_themes/lv_theme_mono.c
    lib/LittleVGL/src/lv_themes/lv_theme_template.c
    lib/LittleVGL/src/lv_core/lv_indev.c
    lib/LittleVGL/src/lv_core/lv_refr.c
    lib/LittleVGL/src/lv_core/lv_style.c
    lib/LittleVGL/src/lv_core/lv_obj.c
    lib/LittleVGL/src/lv_core/lv_disp.c
    lib/LittleVGL/src/lv_core/lv_group.c
    lib/LittleVGL/src/lv_gpu/lv_gpu_nxp_pxp_osa.c
    lib/LittleVGL/src/lv_gpu/lv_gpu_stm32_dma2d.c
    lib/LittleVGL/src/lv_gpu/lv_gpu_nxp_pxp.c
    lib/LittleVGL/src/lv_gpu/lv_gpu_nxp_vglite.c
    lib/LittleVGL/src/lv_misc/lv_gc.c
    lib/LittleVGL/src/lv_misc/lv_log.c
    lib/LittleVGL/src/lv_misc/lv_printf.c
    lib/LittleVGL/src/lv_misc/lv_bidi.c
    lib/LittleVGL/src/lv_misc/lv_ll.c
    lib/LittleVGL/src/lv_misc/lv_mem.c
    lib/LittleVGL/src/lv_misc/lv_templ.c
    lib/LittleVGL/src/lv_misc/lv_fs.c
    lib/LittleVGL/src/lv_misc/lv_txt_ap.c
    lib/LittleVGL/src/lv_misc/lv_txt.c
    lib/LittleVGL/src/lv_misc/lv_task.c
    lib/LittleVGL/src/lv_misc/lv_async.c
    lib/LittleVGL/src/lv_misc/lv_math.c
    lib/LittleVGL/src/lv_misc/lv_utils.c
    lib/LittleVGL/src/lv_misc/lv_area.c
    lib/LittleVGL/src/lv_misc/lv_debug.c
    lib/LittleVGL/src/lv_misc/lv_anim.c
    lib/LittleVGL/src/lv_misc/lv_color.c
    lib/LittleVGL/src/lv_widgets/lv_objx_templ.c
    lib/LittleVGL/src/lv_widgets/lv_table.c
    lib/LittleVGL/src/lv_widgets/lv_btnmatrix.c
    lib/LittleVGL/src/lv_widgets/lv_imgbtn.c
    lib/LittleVGL/src/lv_widgets/lv_page.c
    lib/LittleVGL/src/lv_widgets/lv_slider.c
    lib/LittleVGL/src/lv_widgets/lv_cont.c
    lib/LittleVGL/src/lv_widgets/lv_spinner.c
    lib/LittleVGL/src/lv_widgets/lv_keyboard.c
    lib/LittleVGL/src/lv_widgets/lv_list.c
    lib/LittleVGL/src/lv_widgets/lv_label.c
    lib/LittleVGL/src/lv_widgets/lv_bar.c
    lib/LittleVGL/src/lv_widgets/lv_img.c
    lib/LittleVGL/src/lv_widgets/lv_textarea.c
    lib/LittleVGL/src/lv_widgets/lv_roller.c
    lib/LittleVGL/src/lv_widgets/lv_chart.c
    lib/LittleVGL/src/lv_widgets/lv_calendar.c
    lib/LittleVGL/src/lv_widgets/lv_checkbox.c
    lib/LittleVGL/src/lv_widgets/lv_linemeter.c
    lib/LittleVGL/src/lv_widgets/lv_cpicker.c
    lib/LittleVGL/src/lv_widgets/lv_tabview.c
    lib/LittleVGL/src/lv_widgets/lv_led.c
    lib/LittleVGL/src/lv_widgets/lv_switch.c
    lib/LittleVGL/src/lv_widgets/lv_canvas.c
    lib/LittleVGL/src/lv_widgets/lv_line.c
    lib/LittleVGL/src/lv_widgets/lv_objmask.c
    lib/LittleVGL/src/lv_widgets/lv_tileview.c
    lib/LittleVGL/src/lv_widgets/lv_win.c
    lib/LittleVGL/src/lv_widgets/lv_arc.c
    lib/LittleVGL/src/lv_widgets/lv_btn.c
    lib/LittleVGL/src/lv_widgets/lv_gauge.c
    lib/LittleVGL/src/lv_widgets/lv_dropdown.c
    lib/LittleVGL/src/lv_widgets/lv_msgbox.c
    lib/LittleVGL/src/lv_widgets/lv_spinbox.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_34.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_38.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_32.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_26.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_22.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_24.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_46.c
    lib/LittleVGL/src/lv_font/lv_font_dejavu_16_persian_hebrew.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_18.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_8.c
    lib/LittleVGL/src/lv_font/lv_font_loader.c
    lib/LittleVGL/src/lv_font/lv_font_simsun_16_cjk.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_30.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_36.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_48.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_12_subpx.c
    lib/LittleVGL/src/lv_font/lv_font.c
    lib/LittleVGL/src/lv_font/lv_font_unscii_8.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_42.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_40.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_12.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_10.c
    lib/LittleVGL/src/lv_font/lv_font_fmt_txt.c
    lib/LittleVGL/src/lv_font/lv_font_unscii_16.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_28.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_14.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_28_compressed.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_44.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_16.c
    lib/LittleVGL/src/lv_font/lv_font_montserrat_20.c
    lib/LittleVGL/src/lv_draw/lv_draw_triangle.c
    lib/LittleVGL/src/lv_draw/lv_draw_img.c
    lib/LittleVGL/src/lv_draw/lv_img_buf.c
    lib/LittleVGL/src/lv_draw/lv_draw_arc.c
    lib/LittleVGL/src/lv_draw/lv_draw_mask.c
    lib/LittleVGL/src/lv_draw/lv_img_decoder.c
    lib/LittleVGL/src/lv_draw/lv_draw_rect.c
    lib/LittleVGL/src/lv_draw/lv_draw_line.c
    lib/LittleVGL/src/lv_draw/lv_draw_blend.c
    lib/LittleVGL/src/lv_draw/lv_draw_label.c
    lib/LittleVGL/src/lv_draw/lv_img_cache.c
    lib/LittleVGL/src/lv_hal/lv_hal_disp.c
    lib/LittleVGL/src/lv_hal/lv_hal_indev.c
    lib/LittleVGL/src/lv_hal/lv_hal_tick.c
)

include_directories(
    include
    lib/st75256_lcd
    lib/LittleVGL
)

add_definitions(-DLV_CONF_SIMPLE -D_GNU_SOURCE)

add_executable(lcd_jlx ${SOURCES})

target_link_libraries(lcd_jlx gpiod pthread)
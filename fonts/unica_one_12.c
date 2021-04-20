/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef UNICA_ONE_12
#define UNICA_ONE_12 1
#endif

#if UNICA_ONE_12

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xf9,

    /* U+0022 "\"" */
    0xb4,

    /* U+0023 "#" */
    0x24, 0x49, 0xf9, 0x22, 0x5f, 0xd2, 0x24,

    /* U+0024 "$" */
    0x2f, 0xbb, 0x62, 0x3b, 0xf2,

    /* U+0025 "%" */
    0x13, 0x4d, 0x38, 0xe0, 0xf3, 0x55, 0x5d, 0x0,

    /* U+0026 "&" */
    0xf4, 0xa1, 0xf9, 0x4a, 0x5e,

    /* U+0027 "'" */
    0xc0,

    /* U+0028 "(" */
    0x6a, 0xaa, 0x90,

    /* U+0029 ")" */
    0x95, 0x55, 0x60,

    /* U+002A "*" */
    0x5e, 0x80,

    /* U+002B "+" */
    0x21, 0x3e, 0x40,

    /* U+002C "," */
    0xe0,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x29, 0x24, 0xa4, 0x90,

    /* U+0030 "0" */
    0xf9, 0x99, 0x99, 0x9f,

    /* U+0031 "1" */
    0x6a, 0x22, 0x22, 0x27,

    /* U+0032 "2" */
    0xf9, 0x92, 0x24, 0x8f,

    /* U+0033 "3" */
    0xf9, 0x16, 0x19, 0x9f,

    /* U+0034 "4" */
    0x11, 0x94, 0xa9, 0x7c, 0x42,

    /* U+0035 "5" */
    0xf8, 0x8f, 0x19, 0x9f,

    /* U+0036 "6" */
    0xf9, 0x8f, 0x99, 0x9f,

    /* U+0037 "7" */
    0xf1, 0x12, 0x22, 0x44,

    /* U+0038 "8" */
    0xf9, 0x96, 0x99, 0x9f,

    /* U+0039 "9" */
    0xf9, 0x99, 0xf1, 0x9f,

    /* U+003A ":" */
    0x84,

    /* U+003B ";" */
    0x8e,

    /* U+003C "<" */
    0x34, 0xc2,

    /* U+003D "=" */
    0xf0, 0xf0,

    /* U+003E ">" */
    0xc2, 0x34,

    /* U+003F "?" */
    0xf6, 0x94, 0x82,

    /* U+0040 "@" */
    0x7a, 0x3f, 0xf3, 0x8f, 0xfc, 0xb3, 0xfd, 0xe0,

    /* U+0041 "A" */
    0x31, 0x94, 0xa5, 0x3d, 0x31,

    /* U+0042 "B" */
    0xf9, 0x9e, 0x99, 0x9f,

    /* U+0043 "C" */
    0xf9, 0x98, 0x88, 0x9f,

    /* U+0044 "D" */
    0xf9, 0x99, 0x99, 0x9f,

    /* U+0045 "E" */
    0xf8, 0x88, 0xe8, 0x8f,

    /* U+0046 "F" */
    0xf2, 0x4f, 0x24,

    /* U+0047 "G" */
    0xf9, 0x88, 0xb9, 0x9f,

    /* U+0048 "H" */
    0x99, 0x99, 0xf9, 0x99,

    /* U+0049 "I" */
    0xe9, 0x24, 0x97,

    /* U+004A "J" */
    0x64, 0x92, 0x6f,

    /* U+004B "K" */
    0x9a, 0xac, 0xca, 0xa9,

    /* U+004C "L" */
    0x92, 0x49, 0x27,

    /* U+004D "M" */
    0x8e, 0xf7, 0xbe, 0xd6, 0xb1,

    /* U+004E "N" */
    0x99, 0xdd, 0xdb, 0x99,

    /* U+004F "O" */
    0xf9, 0x99, 0x99, 0x9f,

    /* U+0050 "P" */
    0xe9, 0x99, 0x9f, 0x88,

    /* U+0051 "Q" */
    0xf9, 0x99, 0x99, 0x99, 0x62,

    /* U+0052 "R" */
    0xf9, 0x99, 0xea, 0x99,

    /* U+0053 "S" */
    0xf9, 0x94, 0x29, 0x9f,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x84,

    /* U+0055 "U" */
    0x99, 0x99, 0x99, 0x9f,

    /* U+0056 "V" */
    0x8a, 0x52, 0x95, 0x18, 0xc6,

    /* U+0057 "W" */
    0x93, 0x6a, 0xd5, 0xab, 0x59, 0xb3, 0x26,

    /* U+0058 "X" */
    0x4a, 0x8c, 0x42, 0x29, 0x49,

    /* U+0059 "Y" */
    0x8c, 0x94, 0xa2, 0x10, 0x84,

    /* U+005A "Z" */
    0xf1, 0x22, 0x44, 0x8f,

    /* U+005B "[" */
    0xea, 0xaa, 0xc0,

    /* U+005C "\\" */
    0x92, 0x44, 0x92, 0x44,

    /* U+005D "]" */
    0xd5, 0x55, 0xc0,

    /* U+005E "^" */
    0x66, 0x90,

    /* U+005F "_" */
    0xf8,

    /* U+0060 "`" */
    0x90,

    /* U+0061 "a" */
    0xf9, 0x1f, 0x99, 0x9f,

    /* U+0062 "b" */
    0xf9, 0x9e, 0x99, 0x9f,

    /* U+0063 "c" */
    0xf9, 0x98, 0x88, 0x9f,

    /* U+0064 "d" */
    0xf9, 0x99, 0x99, 0x9f,

    /* U+0065 "e" */
    0xf9, 0x9f, 0x89, 0x9f,

    /* U+0066 "f" */
    0xf2, 0x4f, 0x24,

    /* U+0067 "g" */
    0xf9, 0x88, 0xb9, 0x9f,

    /* U+0068 "h" */
    0x99, 0x99, 0xf9, 0x99,

    /* U+0069 "i" */
    0xff,

    /* U+006A "j" */
    0x24, 0x93, 0x6f,

    /* U+006B "k" */
    0x9a, 0xac, 0xca, 0xa9,

    /* U+006C "l" */
    0x92, 0x49, 0x27,

    /* U+006D "m" */
    0xef, 0x26, 0x4c, 0x99, 0x32, 0x64, 0xc9,

    /* U+006E "n" */
    0xf9, 0x99, 0x99, 0x99,

    /* U+006F "o" */
    0xf9, 0x99, 0x99, 0x9f,

    /* U+0070 "p" */
    0xe9, 0x99, 0x9f, 0x88,

    /* U+0071 "q" */
    0xf4, 0xa5, 0x29, 0x4a, 0x5c, 0x18,

    /* U+0072 "r" */
    0xf6, 0xc9, 0x24,

    /* U+0073 "s" */
    0xf9, 0x94, 0x29, 0x9f,

    /* U+0074 "t" */
    0xf2, 0x49, 0x6f,

    /* U+0075 "u" */
    0x99, 0x99, 0x99, 0x9f,

    /* U+0076 "v" */
    0x8a, 0x52, 0x95, 0x18, 0xc6,

    /* U+0077 "w" */
    0x93, 0x26, 0x4c, 0x99, 0x32, 0x64, 0xf7,

    /* U+0078 "x" */
    0x4a, 0x8c, 0x42, 0x29, 0x49,

    /* U+0079 "y" */
    0x8c, 0x63, 0x18, 0xb8, 0x84,

    /* U+007A "z" */
    0xf1, 0x22, 0x44, 0x8f,

    /* U+007B "{" */
    0x29, 0x25, 0x12, 0x4c,

    /* U+007C "|" */
    0xff, 0xc0,

    /* U+007D "}" */
    0x89, 0x24, 0x52, 0x58,

    /* U+007E "~" */
    0xf0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 44, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 56, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 79, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 3, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 98, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 15, .adv_w = 125, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 23, .adv_w = 98, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 50, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 29, .adv_w = 62, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 32, .adv_w = 62, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 35, .adv_w = 73, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 37, .adv_w = 98, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 40, .adv_w = 50, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 41, .adv_w = 94, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 42, .adv_w = 50, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 73, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 47, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 59, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 63, .adv_w = 98, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 68, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 50, .box_w = 1, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 50, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 90, .adv_w = 98, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 92, .adv_w = 98, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 94, .adv_w = 98, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 96, .adv_w = 84, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 143, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 107, .adv_w = 92, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 97, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 94, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 97, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 85, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 103, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 60, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 73, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 87, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 72, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 123, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 107, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 88, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 98, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 174, .adv_w = 93, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 75, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 100, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 92, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 131, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 87, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 86, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 62, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 220, .adv_w = 73, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 224, .adv_w = 62, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 227, .adv_w = 98, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 229, .adv_w = 81, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 230, .adv_w = 61, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 231, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 97, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 94, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 97, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 103, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 52, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 263, .adv_w = 73, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 87, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 72, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 148, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 280, .adv_w = 101, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 98, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 88, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 292, .adv_w = 98, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 298, .adv_w = 77, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 72, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 308, .adv_w = 101, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 92, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 146, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 87, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 90, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 62, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 342, .adv_w = 52, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 344, .adv_w = 62, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 348, .adv_w = 98, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    34, 53,
    34, 55,
    34, 56,
    34, 58,
    34, 87,
    39, 34,
    39, 43,
    39, 75,
    45, 53,
    45, 55,
    45, 56,
    45, 58,
    45, 87,
    45, 90,
    49, 34,
    49, 75,
    53, 34,
    53, 43,
    55, 34,
    55, 43,
    56, 34,
    56, 43,
    58, 34,
    58, 43,
    71, 34,
    71, 43,
    71, 75,
    77, 53,
    77, 55,
    77, 56,
    77, 58,
    77, 87,
    77, 90,
    81, 34,
    81, 75,
    83, 43,
    83, 75,
    87, 34,
    87, 43
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -12, -4, -4, -8, -4, -8, -10, -9,
    -12, -8, -8, -10, -8, -9, -4, -10,
    -8, -11, -4, -11, -4, -11, -8, -10,
    -8, -10, -9, -12, -8, -8, -10, -8,
    -9, -4, -10, -4, -10, -4, -11
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 39,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t unica_one_12 = {
#else
lv_font_t unica_one_12 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 12,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UNICA_ONE_12*/


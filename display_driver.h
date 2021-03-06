#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#define NONE            0

#define DISP_CONSOLE    1 // printf
// Add more display macros here, as implemented

#ifndef DISP_SCREEN
    #define DISP_SCREEN NONE
#endif

#if DISP_SCREEN == DISP_CONSOLE
    #include "displays/default/console_display.h"
    #define disp_write_command       console_display_write_command
    #define disp_write_data          console_display_write_data
    #define disp_hard_reset          console_display_hard_reset
    #define disp_sub_sleep_enable    console_display_sleep_enable
    #define disp_sub_sleep_disable   console_display_sleep_disable
    #define disp_set_row_address     console_display_set_row_address
    #define disp_set_column_address  console_display_set_column_address
    #define disp_sub_init            console_display_init
    #define disp_sub_display_on      console_display_on
    #define disp_start_write         console_display_start_write
    #define disp_end_write           console_display_end_write

    #define DISP_WIDTH               CONSOLE_DISPLAY_WIDTH
    #define DISP_HEIGHT              CONSOLE_DISPLAY_HEIGHT

// Add more display implementations here, in #elif structure

#endif

// Font library
#include "GFXfont/gfxfont.h"

/* All configurations:
     Color format is 16bit (RRRR_RGGG_GGGB_BBBB)
     Interface mode is 4-wire serial
*/
#define DISP_FORMAT_COLOR(r, g, b) (((r&0x1f)<<11) | ((g&0x3f)<<5) | (b&0x1f))

#define DISP_PIXEL_BLACK          0x0000
#define DISP_PIXEL_GREY           0x8410
#define DISP_PIXEL_WHITE          0xffff
#define DISP_PIXEL_RED            0xf800
#define DISP_PIXEL_YELLOW         0xffe0
#define DISP_PIXEL_GREEN          0x07e0
#define DISP_PIXEL_CYAN           0x07ff
#define DISP_PIXEL_BLUE           0x001f
#define DISP_PIXEL_MAGENTA        0xf81f

#define DISP_BG_COLOR             DISP_PIXEL_BLACK

#ifndef MAX_WRITE_ID
    #define MAX_WRITE_ID 10
#endif

void disp_init(void);
void disp_set_pos(uint8_t x, uint8_t y);
void disp_write_pixel(uint16_t color);
void disp_write_pixel_at(uint8_t x, uint8_t y, uint16_t color);
void disp_draw_line(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint16_t color);
void disp_draw_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);
void disp_fill_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);
void disp_clear_screen(uint16_t color);
void disp_write(uint8_t c);
void disp_write_str(char *str);
void disp_write_str_group(char *str, uint8_t replace_last);
void disp_remove_str_group(uint8_t replace_last);
void disp_end_group(void);
void disp_get_text_bounds(char *str, uint8_t x, uint8_t y, uint8_t *x1, uint8_t *y1, uint8_t *w, uint8_t *h);
void disp_set_font(GFXfont *font);
void disp_set_font_scale(uint8_t scale);
void disp_set_wrap(uint8_t val);
void disp_set_cp437(uint8_t val);
void disp_set_color(uint16_t text, uint16_t bg);
void disp_sleep_enable();
void disp_sleep_disable();

#endif

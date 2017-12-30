#include "display_driver.h"
#include "GFXfont/Fonts/FreeMono9pt7b.h"
#include "GFXfont/Fonts/FreeSans9pt7b.h"

int main() {
    disp_init();

    disp_start_write();
    disp_set_font(&FreeSans9pt7b);
    disp_set_pos(0,15); // y-coordinate defines bottom (base) line of text
    disp_write_str("Hello, world!");

    uint8_t x1;
    uint8_t y1;
    uint8_t w;
    uint8_t h;
    disp_get_text_bounds("Hello, world!", 0, 15, &x1, &y1, &w, &h);
    printf("x:%d, y:%d, w:%d, h:%d\n", x1, y1, w, h);

    disp_set_font(&FreeMono9pt7b);
    disp_set_color(DISP_PIXEL_GREEN, DISP_BG_COLOR);
    disp_write_str("\n\n:)");

    disp_end_write();

    return 0;
}

#include "console_display.h"

static uint8_t xs, ys, xe, ye;
static char fb[CONSOLE_DISPLAY_WIDTH][CONSOLE_DISPLAY_HEIGHT];

void console_display_init(void) {
    xs = 0;
    ys = 0;
    xe = CONSOLE_DISPLAY_WIDTH-1;
    ye = CONSOLE_DISPLAY_HEIGHT-1;
    int x, y;
    for (y=0; y<CONSOLE_DISPLAY_HEIGHT; y++)
        for (x=0; x<CONSOLE_DISPLAY_WIDTH; x++)
            fb[x][y] = '_';
}

void console_display_write_command(uint8_t command) {
}

static int fix_2write_16_bit = 0;
void console_display_write_data(uint8_t data) {
    if (fix_2write_16_bit) {
        fb[xs][ys] = data>0 ? 'X' : '_';
        if (++xs>xe) {
            xs = 0;
            if (++ys>ye)
                ys = 0;
        }
        fix_2write_16_bit = 0;
    } else fix_2write_16_bit = 1;
}

void console_display_end_write(void) {
    int x, y;
    for (y=0; y<CONSOLE_DISPLAY_HEIGHT; y++) {
        for (x=0; x<CONSOLE_DISPLAY_WIDTH; x++)
            printf("%c", fb[x][y]);
        printf("\n");
    }
    printf("\n");
}

void console_display_set_row_address(uint8_t start_address, uint8_t end_address) {
    ys = start_address;
    ye = end_address;
}

void console_display_set_column_address(uint8_t start_address, uint8_t end_address) {
    xs = start_address;
    xe = end_address;
}
// graphics/directx.c
// Windows 10 Emulator - Minimal Graphics (ASCII)

#include "directx.h"
#include <stdio.h>
#include <string.h>

static char fb[FB_HEIGHT][FB_WIDTH + 1];

void gfx_init(void) {
    for (int y = 0; y < FB_HEIGHT; ++y) {
        for (int x = 0; x < FB_WIDTH; ++x) fb[y][x] = ' ';
        fb[y][FB_WIDTH] = '\0';
    }
}

void gfx_clear(void) {
    for (int y = 0; y < FB_HEIGHT; ++y) {
        for (int x = 0; x < FB_WIDTH; ++x) fb[y][x] = ' ';
    }
}

void gfx_draw_text(int x, int y, const char* text) {
    if (y < 0 || y >= FB_HEIGHT) return;
    int len = (int)strlen(text);
    for (int i = 0; i < len; ++i) {
        int xx = x + i;
        if (xx >= 0 && xx < FB_WIDTH) {
            fb[y][xx] = text[i];
        }
    }
}

void gfx_present(void) {
    // basit terminal çizimi
    printf("\n+");
    for (int x = 0; x < FB_WIDTH; ++x) printf("-");
    printf("+\n");
    for (int y = 0; y < FB_HEIGHT; ++y) {
        printf("|%s|\n", fb[y]);
    }
    printf("+");
    for (int x = 0; x < FB_WIDTH; ++x) printf("-");
    printf("+\n");
}

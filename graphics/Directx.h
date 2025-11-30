// graphics/directx.h
// Windows 10 Emulator - Minimal Graphics Interface (ASCII framebuffer)

#ifndef DIRECTX_H
#define DIRECTX_H

#include <stdint.h>

#define FB_WIDTH  40
#define FB_HEIGHT 12

void gfx_init(void);
void gfx_clear(void);
void gfx_draw_text(int x, int y, const char* text);
void gfx_present(void);

#endif // DIRECTX_H

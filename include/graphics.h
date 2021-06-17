#ifndef GFX_H
#define GFX_H

#include <stdint.h>
#include <ports.h>
#include <rect.h>
#define VGA_WIDTH 320
#define VGA_HEIGHT 200
#define VGA_13H 0xa0000

void plotpix(char pix, uint16_t x, uint8_t y);
void drawimg(unsigned char* mem, uint16_t x, uint8_t y);
void plotrect(char pix, rect* r);

#endif

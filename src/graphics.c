#include <graphics.h>
#include <lc.h>
#include <rect.h>

// render tools
void plotpix(char pix, uint16_t x, uint8_t y) {

	if(x > VGA_WIDTH || y > VGA_HEIGHT) return;
	char * vga = (char *) VGA_13H;
	vga[(y)*VGA_WIDTH+x] = pix;

}

void drawimg(unsigned char* mem, uint16_t x, uint8_t y) {
	uint32_t p = 0;
	uint16_t cx = x;
	while(1) {
		if(mem[p] == 255) break;
		if(mem[p] == 254) { y++; cx = x; p++; continue;}
		plotpix(mem[p], cx, y);
		p++;
		cx++;
	}

}

void plotrect(char pix, rect* r) {

	for(uint8_t y = r->y; y < r->y + r->h; y++) {
		
		for(uint16_t x = r->x; x < r->x + r->w; x++) {

			plotpix(pix, x, y);

		}

	}

}

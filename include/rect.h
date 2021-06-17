#ifndef RECT_H
#define RECT_H

#include <stdint.h>

typedef struct rect {
	
	int x, y, w, h;
	
} rect;

typedef struct ball {
	// rect but the w,h dont change
	rect ball;
	// signed 8b int because ball wont be moving fuckin 128^2 pixels/sec
	int8_t vx;
	int8_t vy;
} ball;

rect rect_overlap(rect* this, rect* test);
rect bricks[75];

#endif
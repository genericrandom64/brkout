#ifndef LC_H
#define LC_H

#include <stdint.h>

#define low_16(address) (uint16_t)((address) & 0xFFFF)
#define high_16(address) (uint16_t)(((address) >> 16) & 0xFFFF)

#define NULL (void *)0

#define sign_of(x) ( (x < 0) ? -1 : ( (x > 0) ? 1 : 0) )

int abs(int i);
int max(int a, int b);
int min(int a, int b);

#endif

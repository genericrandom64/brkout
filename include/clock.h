#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>
#include <ports.h>
#include <idt.h>
#include <isr.h>
#include <lc.h>

void init_timer(uint32_t freq);
uint32_t tick;

#endif

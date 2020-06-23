//Code des anciens simplifié par NPXav
#pragma once
#include <stdint.h>

// RCC Clock Frequency [Hz]
#define RCC_CLOCK_FREQ_HZ (     64000000)

// Interruptions = 10kHz = 100us (beaucoup ?)
#define SYSTICK_FREQ_HZ   (       100000)
#define SYSTICK_PERIOD    (RCC_CLOCK_FREQ_HZ / SYSTICK_FREQ_HZ)


#define MICROS_SYSTICK_RATIO (1000000 / SYSTICK_FREQ_HZ)

#define MILLIS_TO_SYSTICK(ms) (ms * 1000 / MICROS_SYSTICK_RATIO)
#define SYSTICK_TO_MILLIS(ticks) (ticks * MICROS_SYSTICK_RATIO / 1000)

void clock_setup();

uint32_t get_frequency();
uint32_t get_systicks();
uint32_t get_uptime_ms();

void delay_ms(uint32_t ms);

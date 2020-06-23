//Code des anciens mais validé par NPXav
#include "include/clock.h"

#include <libopencm3/cm3/systick.h>
#include <libopencm3/stm32/rcc.h>

void clock_setup() {
  rcc_clock_setup_hsi(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);
  // SystemCoreClock = ((INPUT_CLOCK (HSE_OR_HSI_IN_HZ) / PLL_M) * PLL_N) / PLL_P

  systick_set_clocksource(STK_CSR_CLKSOURCE_AHB);
  // Interrupts each millisec
  systick_set_reload(SYSTICK_PERIOD - 1);
  // clear counter so it starts right away
  systick_clear();
  systick_counter_enable();
  systick_interrupt_enable();
}

volatile uint32_t systicks = 0;
void sys_tick_handler() {
  systicks++;
}


uint32_t get_systicks() {
  return systicks;
}
uint32_t get_uptime_ms() {
  return systicks;
}

void delay_ms(uint32_t ms) {
  uint32_t count_max = systicks + MILLIS_TO_SYSTICK(ms);
  while(systicks < count_max) {}
}


const uint32_t millisec = 1600;
//const uint32_t second = millisec*1000;

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

//debug led (green) (flash test2020)
#define GPIO_DEBUG_LED_PORT_RCC RCC_GPIOB
#define GPIO_DEBUG_LED_PORT     GPIOB
#define GPIO_DEBUG_LED_PIN      GPIO3

void gpio_setup();
void debug_led_toggle();

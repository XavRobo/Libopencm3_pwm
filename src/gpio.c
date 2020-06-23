#include "include/gpio.h"

void gpio_setup(void){
	//setup led_pin
	rcc_periph_clock_enable(GPIO_DEBUG_LED_PORT_RCC);
	gpio_mode_setup(GPIO_DEBUG_LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_DEBUG_LED_PIN);
}

void debug_led_toggle(){
    gpio_toggle(GPIO_DEBUG_LED_PORT, GPIO_DEBUG_LED_PIN);
}

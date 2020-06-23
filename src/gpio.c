#include "include/gpio.h"

void gpio_setup(void){
	//setup led_pin
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_IOPBEN);
	
	gpio_mode_setup(GPIO_DEBUG_LED_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,GPIO_DEBUG_LED_PIN);
    gpio_set_output_options(GPIO_DEBUG_LED_PORT, GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ, GPIO_DEBUG_LED_PIN);  

	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_IOPAEN);

	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO1);
	gpio_set_output_options(GPIOA, GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ, GPIO1);
}

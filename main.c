//#include "include/servo.h"
#include "include/clock.h"
#include "include/gpio.h"

void test20_led_blink(){
    //gpio initialized before

    //blink, just to test flash
    while (true) {
        debug_led_toggle();
        delay_ms(500);
    }
}

int main(void){
	clock_setup();
	gpio_setup();

	test20_led_blink();

	return 0;
}

#include "include/servo.h"
#include "include/clock.h"
#include "include/gpio.h"

int main(void){
	clock_setup();
	gpio_setup();
	servo_setup();

	//test20_led_blink();

	return 0;
}

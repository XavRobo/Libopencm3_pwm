#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

#include "include/servo.h"
#include "include/pwm.h"


void servo_setup(void)
{
     /* init timer3 with a period of 20ms */
     pwm_setup_timer(&RCC_APB1ENR, RCC_APB1ENR_TIM3EN, TIM3, PWM_PRESCALE, PWM_PERIOD);

     /* init output of channel2 of timer3 */
     pwm_setup_output_channel(TIM3, SERVO_A_TIMCH, &RCC_AHBENR, RCC_AHBENR_IOPAEN, GPIOA, GPIO6);

     /* init output of channel3 of timer3 */
     pwm_setup_output_channel(TIM3, SERVO_B_TIMCH, &RCC_AHBENR, RCC_AHBENR_IOPAEN, GPIOA, GPIO4);

     pwm_set_pulse_width(TIM3, SERVO_A_TIMCH, 10000);
     pwm_set_pulse_width(TIM3, SERVO_B_TIMCH, 5000);

     /* start timer1 */
     pwm_start_timer(TIM3);
}

void servo_set_position(enum tim_oc_id ch, uint32_t pos_us)
{
     pwm_set_pulse_width(TIM3, ch, pos_us);
}

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "include/pwm.h"

void pwm_setup_timer(enum rcc_periph_clken 	clken, uint32_t timer_peripheral, uint32_t prescaler, uint32_t period)
{
     /* Enable timer clock. */
     //rcc_peripheral_enable_clock(reg, en); version online
     rcc_periph_clock_enable(clken);
     

     /* Reset TIM1 peripheral */
     //timer_reset(timer_peripheral);

     /* Set the timers global mode to:
      * - use no divider
      * - alignment edge
      * - count direction up
      */
     timer_set_mode(timer_peripheral,
                    TIM_CR1_CKD_CK_INT,
                    TIM_CR1_CMS_EDGE,
                    TIM_CR1_DIR_UP);

     timer_set_prescaler(timer_peripheral, prescaler);
     timer_set_repetition_counter(timer_peripheral, 0);
     timer_enable_preload(timer_peripheral);
     timer_continuous_mode(timer_peripheral);
     timer_set_period(timer_peripheral, period);
}

void pwm_setup_output_channel(uint32_t timer_peripheral, enum tim_oc_id oc_id, enum rcc_periph_clken clken, uint32_t gpio_port, uint16_t gpio_pin)
{
     /* Enable GPIO clock. */
     //rcc_peripheral_enable_clock(gpio_reg, gpio_en); version online
     rcc_periph_clock_enable(clken);

     /* Set timer channel to output */
     gpio_mode_setup(gpio_port,GPIO_MODE_AF,GPIO_PUPD_NONE,gpio_pin);
     gpio_set_output_options(gpio_port, GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ, gpio_pin);     
	 gpio_set_af(gpio_port,GPIO_AF2,gpio_pin);

     timer_disable_oc_output(timer_peripheral, oc_id);
     timer_set_oc_mode(timer_peripheral, oc_id, TIM_OCM_PWM1);
     timer_enable_oc_preload(timer_peripheral, oc_id);
     timer_set_oc_value(timer_peripheral, oc_id, 0);
     timer_enable_oc_output(timer_peripheral, oc_id);
}

void pwm_set_pulse_width(uint32_t timer_peripheral, enum tim_oc_id oc_id, uint32_t pulse_width)
{
     timer_set_oc_value(timer_peripheral, oc_id, pulse_width);
}

void pwm_start_timer(uint32_t timer_peripheral)
{
	timer_generate_event(timer_peripheral, TIM_EGR_UG);
    timer_enable_counter(timer_peripheral);
}

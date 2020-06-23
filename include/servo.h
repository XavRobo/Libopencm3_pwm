#ifndef __SERVO_H_
#define __SERVO_H_

#include <libopencm3/stm32/timer.h>

/**
 * Prescale 64000000 Hz system clock by 64 = 1000000 Hz.
 */
#define PWM_PRESCALE	(64)

/**
 * We need a 50 Hz period (1000 / 20ms = 50), thus devide 100000 by 50 = 20000 (us).
 */
#define PWM_PERIOD		(20000)

/**
 * TIM3 channel for servo 1.
 *
 * Changing this also requires to change settings in {@link servo_init}!
 */
#define SERVO_A_TIMCH		TIM_OC1

/**
 * TIM3 channel for servo 2.
 *
 * Changing this also requires to change settings in {@link servo_init}!
*/
#define SERVO_B_TIMCH		TIM_OC2

/**
 * Initialize and start the PWM used for the servos, drive servos to middle position.
 */
void servo_setup(void);

/**
 * Drive the servo connected to the given channel to the given position in us.
 *
 * @param[in]	ch		The channel of the servo. E.g. SERVO_A_TIMCH, SERVO_B_TIMCH.
 * @param[in]	pos_us	The position in us to which to drive the servo to.
 */
void servo_set_position(enum tim_oc_id ch, uint32_t pos_us);

#endif

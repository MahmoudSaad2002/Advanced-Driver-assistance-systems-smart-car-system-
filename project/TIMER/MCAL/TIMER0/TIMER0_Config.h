/*
 * TIMER0_Config.h
 *
 *  Created on: 11 Aug 2024
 *      Author: ahmed
 */

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_

/******************************************************************************/
/***************************MOODS OF TIMER0************************************/
/******************************************************************************/
/* OPTIONS
 * Normal_MOOD
 * CTC_MOOD
 * PWM_PhaseCorrect_MOOD
 * FAST_PWM_MOOD
 */
/******************************************************/
#define TIMER0_Mood          CTC_MOOD
/******************************************************/

/**********************   PRESCALER MOODS   **********************************/
/*****************************************************************************/
/* OPTIONS
 * NO_CLOCK_TIMER0
 * NO_PRESCALER_TIMER0
 * PRESCALER_TIMER0_8
 * PRESCALER_TIMER0_64
 * PRESCALER_TIMER0_256
 * PRESCALER_TIMER0_1024
 * EXT_CLOCK_TIMER0_FALLING
 * EXT_CLOCK_TIMER0_RISING
 */
/******************************************************/
#define Prescaler_Mood           PRESCALER_TIMER0_1024
/*******************************************************/


/***************************Definitions of TIMER0 OC0_PIN**********************/
/******************************************************************************/
/* OPTIONS
 * Normal_port_operation
 * Toggle_OC0
 * Clear_OC0
 * Set_OC0
 * Reserved
*/
/******************************************************/
#define OC0_MOOD         Normal_port_operation
/******************************************************/
#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */

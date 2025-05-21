/*
 * TIMER0_Interface.h
 *
 *  Created on: 11 Aug 2024
 *      Author: ahmed
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

void TMR0_VoidInit(void);
void TMR0_VoidOVFInterruptEnable(void);
void TMR0_VoidOCMInterruptEnable(void);

void TMR0_VoidSetPreLoad(u8 A_u8PreLoading_Value);
void TMR0_VoidSetOCMValue(u8 A_u8CompareMatchValue);

void TMR0_VidSetDutyCycle(u8 LOC_u8DutyPercentage);

void TMR0_OFV_SetCallBack(void(*PTR)(void));
void TMR0_OCM_SetCallBack(void(*PTR)(void));

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */

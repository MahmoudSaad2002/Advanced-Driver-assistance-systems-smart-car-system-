/*
 * TIMER0_Program.c
 *
 *  Created on: 11 Aug 2024
 *      Author: ahmed
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "TIMER0_Register.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "TIMER0_config.h"

static void (*OVF_GPCALLBACK_PTR)(void) = NULL_PTR;
static void (*OCM_GPCALLBACK_PTR)(void) = NULL_PTR;

void TMR0_VoidInit(void)
{
	/***************************MOODS OF TIMER0************************************/
#if     TIMER0_Mood==Normal_MOOD
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif   TIMER0_Mood==PWM_PhaseCorrect_MOOD
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif    TIMER0_Mood==CTC_MOOD
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#elif   TIMER0_Mood==FAST_PWM_MOOD
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#endif

#if Prescaler_Mood == NO_CLOCK_TIMER0
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
#elif Prescaler_Mood == NO_PRESCALER_TIMER0
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
#elif Prescaler_Mood == PRESCALER_TIMER0_8
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
#elif Prescaler_Mood == PRESCALER_TIMER0_64
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
#elif Prescaler_Mood == PRESCALER_TIMER0_256
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#elif Prescaler_Mood == PRESCALER_TIMER0_1024
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#elif Prescaler_Mood == EXT_CLOCK_TIMER0_FALLING
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#elif Prescaler_Mood == EXT_CLOCK_TIMER0_RISING
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#else

#endif

#if OC0_MOOD == Normal_port_operation
	CLR_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
#elif OC0_MOOD == Toggle_OC0
	SET_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
#elif OC0_MOOD == Clear_OC0
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
#elif OC0_MOOD == Set_OC0
	SET_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
#else

#endif
}
void TMR0_VoidOVFInterruptEnable(void)
{
	SET_BIT(TIMSK, TOIE0);
}
void TMR0_VoidOCMInterruptEnable(void)
{
	SET_BIT(TIMSK, OCIE0);
	SET_BIT(SREG,7);
}

void TMR0_VoidSetPreLoad(u8 A_u8PreLoading_Value)
{
	TCNT0 = A_u8PreLoading_Value;
}
void TMR0_VoidSetOCMValue(u8 A_u8CompareMatchValue)
{
	OCR0 = A_u8CompareMatchValue;
}

void TMR0_VidSetDutyCycle(u8 LOC_u8DutyPercentage)
{
	OCR0=(LOC_u8DutyPercentage*255)/100;
}

void TMR0_OFV_SetCallBack(void(*PTR)(void))
{
	OVF_GPCALLBACK_PTR = PTR;
}
void TMR0_OCM_SetCallBack(void(*PTR)(void))
{
	OCM_GPCALLBACK_PTR = PTR;
}
void __vector_11 (void)__attribute__ ((signal,used, externally_visible));\
void __vector_11 (void)
{
	if(OVF_GPCALLBACK_PTR != NULL_PTR)
	{
		OVF_GPCALLBACK_PTR();
	}
}

void __vector_10 (void)__attribute__ ((signal,used, externally_visible));\
void __vector_10 (void)
{
	if(OCM_GPCALLBACK_PTR != NULL_PTR)
	{
		OCM_GPCALLBACK_PTR();
	}
}


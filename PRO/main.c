/*
 * main.c
 *
 *  Created on: Aug 25, 2024
 *      Author: ahmed
 */
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/EXIT_interrupt/EXT_INTERUPT_int.h"
#include "FUN.h"
#include "HAL/LCD/LCD_int.h"
#include "MCAL/DIO/DIO_int.h"
#include "MCAL/DIO/DIO_private.h"
#include "HAL/Ultrasonic_Sensor/Ultrasonic_int.h"
#include "MCAL/ADC/ADC_int.h"
#include "MCAL/ADC/ADC_conf.h"
#include "TIMER/MCAL/TIMER0/TIMER0_Interface.h"
#include "TIMER/MCAL/TIMER0/TIMER0_Config.h"
#include <util/delay.h>


int main (void)
{
	/********************************LED*********************************/

	MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN4,DIO_OUTPUT_PIN);
	MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN5,DIO_OUTPUT_PIN);
	MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN6,DIO_OUTPUT_PIN);

	/********************************************************************/

	/********************************BUZZER*********************************/

		MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT_PIN);


	/********************************************************************/

	/*******************************INTERPUT*****************************/

	MEXTI_voidInit();
	MINT0_voidSetCallback(Select_GearBox);
	MINT1_voidSetCallback(SL);
	MINT2_voidSetCallback(CCS);
	MDIO_voidSetPinDir(DIO_PORTD,DIO_PIN2,DIO_INPUT_PIN);
	MDIO_voidSetPinDir(DIO_PORTD,DIO_PIN3,DIO_INPUT_PIN);
	MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN2,DIO_INPUT_PIN);

	/********************************************************************/

	/***************************INIT PHERIPHERAL*************************/

	HLCD_voidInit();
	HUltrasonic_voidInt();


	/********************************************************************/

	/********************************** TIMER ***************************/

	TMR0_VoidInit();
	TMR0_VoidOCMInterruptEnable();
	TMR0_VoidSetOCMValue(200);
	//TMR0_OCM_SetCallBack(BAZZER);

	/********************************************************************/

	/********************************* ADC ******************************/

	MADC_voidInt();
	MADC_voidSetCallback(Print_Kilometer);
	//MADC_voidStartConversion(CHANNEL_0);
	HLCD_voidClrScreen();

	/********************************************************************/
	Reseive_Uart();
	DesplayLCD();
	TMR0_OCM_SetCallBack(BAZZER);
	MADC_voidStartConversion(CHANNEL_0);
	MADC_voidSetCallback(Print_Kilometer);
	//DesplayLCD();
	while(1)
	{
		BAS_System();
		_delay_ms(500);
		MADC_voidStartConversion(CHANNEL_0);
	}


	return 0;
}



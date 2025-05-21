/*
 * program.C
 *
 *  Created on: Aug 25, 2024
 *      Author: mahmoud saad 
 */
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "FUN.h"
#include "MCAL/UART/UART_int.h"
#include "HAL/LCD/LCD_int.h"
#include "HAL/Ultrasonic_Sensor/Ultrasonic_int.h"
#include "MCAL/DIO/DIO_int.h"
#include "MCAL/DIO/DIO_private.h"
#include "MCAL/ADC/ADC_int.h"
#include "MCAL/ADC/ADC_conf.h"
#include <util/delay.h>
u8 WelcomeMass[]="WELCOME";
static u8 Select=0;
static u8 flag=0;
static u16 Counts=0;
void Reseive_Uart(void)
{
	u8 Flag=1,Data;
	MUART_voidInit();
	HLCD_voidClrScreen();
	while (Flag==1)
	{
		Data=MUART_u8ReceiveData();
		if (Data=='A')
		{
			Flag=0;
			HLCD_voidMovCursor(1,5);
			HLCD_voidDispStr( WelcomeMass);
			_delay_ms(1000);
			HLCD_voidClrScreen();
		}
	}
}

void Select_GearBox(void)
{
	Select=(Select+1)%4;
	switch (Select)
	{
	case 0: HLCD_voidMovCursor(2,11); HLCD_voidSendData('N'); break;
	case 1: HLCD_voidMovCursor(2,11); HLCD_voidSendData('D'); break;
	case 2: HLCD_voidMovCursor(2,11); HLCD_voidSendData('P'); break;
	case 3: HLCD_voidMovCursor(2,11); HLCD_voidSendData('R'); break;
	}
	clearCount();
}

void DesplayLCD(void)
{
	HLCD_voidMovCursor(1,1); HLCD_voidDispStr("BAS:OFF");
	HLCD_voidMovCursor(2,1); HLCD_voidDispStr("CCS:OFF");
	HLCD_voidMovCursor(1,9); HLCD_voidDispStr("SL:OFF");
	HLCD_voidMovCursor(2,9); HLCD_voidDispStr("G:N");
	HLCD_voidMovCursor(2,15); HLCD_voidDispStr("KM");
}

void BAS_System(void)
{


	static u8 change =0;
	if((Select==1)&&(change==0))
	{
		HLCD_voidMovCursor(1,5); HLCD_voidDispStr("ON ");
		change=1;
		MDIO_voidSetPinVal(DIO_PORTB,DIO_PIN4);
		//Ultrasonic_Action();
	}
	else if ((Select!=1)&&(change==1))
	{
		HLCD_voidMovCursor(1,5); HLCD_voidDispStr("OFF");
		change=2;
		MDIO_voidClrPinVal(DIO_PORTB,DIO_PIN4);
	}
	else if ((Select==3))
	{
		change =0;
	}




}

void Ultrasonic_Action(void)
{

	u16 distance=0;
	if (Select==1)
	{
	distance=HUltrasonic_u16CalcDistance();
	if(distance > 10 )
	{
		flag=0;
		MDIO_voidClrPinVal(DIO_PORTB,DIO_PIN4);
	}
	else if ((distance <= 10 ) && (distance >= 5))
	{

		flag=1;
		MDIO_voidSetPinVal(DIO_PORTB,DIO_PIN4);
		_delay_ms(300);
		MDIO_voidClrPinVal(DIO_PORTB,DIO_PIN4);
		_delay_ms(300);

	}
	else if (distance < 5)
	{
		flag=0;
		MDIO_voidSetPinVal(DIO_PORTB,DIO_PIN4);
	}
	}
	else
	{
	MDIO_voidClrPinVal(DIO_PORTB,DIO_PIN4);
	}



}

void SL(void)
{
	static u8 Change=0;

	if((Select==1)&&(Change==0))
		{
			HLCD_voidMovCursor(1,12); HLCD_voidDispStr("ON ");
			Change=1;
			MDIO_voidSetPinVal(DIO_PORTB,DIO_PIN5);
		}
		else if ((Select!=1)&&(Change==1))
		{
			HLCD_voidMovCursor(1,12); HLCD_voidDispStr("OFF");
			MDIO_voidClrPinVal(DIO_PORTB,DIO_PIN5);
			Change=2;
		}
		else if ((Select==3))
		{
			Change =0;
		}
	clearCount();


}

void Print_Kilometer(void)
{
	u16 Gas_Potentiometer_Value;
	Gas_Potentiometer_Value = MADC_u16GetADCData();
	HLCD_voidMovCursor(2,12);
	HLCD_voidDispIntNum(Gas_Potentiometer_Value/10);
}

void CCS (void)
{
	static u8 CHange=0;

		if((Select==1)&&(CHange==0))
			{
				HLCD_voidMovCursor(2,5); HLCD_voidDispStr("ON ");
				CHange=1;
				MDIO_voidSetPinVal(DIO_PORTB,DIO_PIN6);
			}
			else if ((Select!=1)&&(CHange==1))
			{
				HLCD_voidMovCursor(2,5); HLCD_voidDispStr("OFF");
				MDIO_voidClrPinVal(DIO_PORTB,DIO_PIN6);
				CHange=2;
			}
			else if ((Select==3))
			{
				CHange =0;
			}
		clearCount();

}

void BAZZER (void)
{
	if (Counts==195)
	{
	MDIO_voidSetPinVal(DIO_PORTB,DIO_PIN0);
	_delay_ms(300);
	MDIO_voidClrPinVal(DIO_PORTB,DIO_PIN0);
	_delay_ms(300);
	Counts=0;
	}
	else
	{
		Counts++;
	}


}

void clearCount (void)
{
	Counts=0;
}



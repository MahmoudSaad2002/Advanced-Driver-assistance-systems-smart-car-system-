/*
 * DIO_Program.c

 *
 *  Created on: 1 Aug 2024
 *      Author: ahmed
 */
#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"
#include"DIO_Register.h"
#include"DIO_Private.h"
#include"DIO_Config.h"
#include"DIO_Interface.h"

void MDIO_void_SetPinDirection(u8 A_u8_PortNumber, u8 A_u8_PinNumber, u8 A_u8_PinDirection)
{
	if(DIO_u8_PIN_OUTPUT == A_u8_PinDirection)
	{
		switch(A_u8_PortNumber)
		{
		case DIO_u8_PORTA: SET_BIT(DIO_u8_DDRA_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTB: SET_BIT(DIO_u8_DDRB_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTC: SET_BIT(DIO_u8_DDRC_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTD: SET_BIT(DIO_u8_DDRD_REG,A_u8_PinNumber); break;
		default: break;
		}
	}
	else if(DIO_u8_PIN_INPUT == A_u8_PinDirection)
	{
		switch(A_u8_PortNumber)
		{
		case DIO_u8_PORTA: CLR_BIT(DIO_u8_DDRA_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTB: CLR_BIT(DIO_u8_DDRB_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTC: CLR_BIT(DIO_u8_DDRC_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTD: CLR_BIT(DIO_u8_DDRD_REG,A_u8_PinNumber); break;
		default: break;
		}
	}
	else
	{

	}
}
void MDIO_void_WritePin(u8 A_u8_PortNumber, u8 A_u8_PinNumber, u8 A_u8_PinValue)
{
	if(DIO_u8_HIGH == A_u8_PinValue)
	{
		switch(A_u8_PortNumber)
		{
		case DIO_u8_PORTA: SET_BIT(DIO_u8_PORTA_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTB: SET_BIT(DIO_u8_PORTB_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTC: SET_BIT(DIO_u8_PORTC_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTD: SET_BIT(DIO_u8_PORTD_REG,A_u8_PinNumber); break;
		default: break;
		}
	}
	else if(DIO_u8_LOW == A_u8_PinValue)
	{
		switch(A_u8_PortNumber)
		{
		case DIO_u8_PORTA: CLR_BIT(DIO_u8_PORTA_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTB: CLR_BIT(DIO_u8_PORTB_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTC: CLR_BIT(DIO_u8_PORTC_REG,A_u8_PinNumber); break;
		case DIO_u8_PORTD: CLR_BIT(DIO_u8_PORTD_REG,A_u8_PinNumber); break;
		default: break;
		}
	}
	else
	{

	}
}
u8 MDIO_u8_ReadPin(u8 A_u8_PortNumber, u8 A_u8_PinNumber)
{
	u8 L_u8_BitValue = 0;
	switch(A_u8_PortNumber)
	{
	case DIO_u8_PORTA: L_u8_BitValue = GET_BIT(DIO_u8_PINA_REG,A_u8_PinNumber); break;
	case DIO_u8_PORTB: L_u8_BitValue = GET_BIT(DIO_u8_PINB_REG,A_u8_PinNumber); break;
	case DIO_u8_PORTC: L_u8_BitValue = GET_BIT(DIO_u8_PINC_REG,A_u8_PinNumber); break;
	case DIO_u8_PORTD: L_u8_BitValue = GET_BIT(DIO_u8_PIND_REG,A_u8_PinNumber); break;
	default: break;
	}
	return L_u8_BitValue;
}
void MDIO_void_TogglePin(u8 A_u8_PortNumber, u8 A_u8_PinNumber)
{
	switch(A_u8_PortNumber)
	{
	case DIO_u8_PORTA: TOG_BIT(DIO_u8_PORTA_REG,A_u8_PinNumber); break;
	case DIO_u8_PORTB: TOG_BIT(DIO_u8_PORTB_REG,A_u8_PinNumber); break;
	case DIO_u8_PORTC: TOG_BIT(DIO_u8_PORTC_REG,A_u8_PinNumber); break;
	case DIO_u8_PORTD: TOG_BIT(DIO_u8_PORTD_REG,A_u8_PinNumber); break;
	default: break;
	}
}
void MDIO_voidSetPortDirection(u8 Copy_u8PortNumber ,u8 Copy_u8PortDirection)
{
	switch (Copy_u8PortNumber)
	{
	case DIO_u8_PORTA: DIO_u8_DDRA_REG = Copy_u8PortDirection; break;
	case DIO_u8_PORTB: DIO_u8_DDRB_REG = Copy_u8PortDirection; break;
	case DIO_u8_PORTC: DIO_u8_DDRC_REG = Copy_u8PortDirection; break;
	case DIO_u8_PORTD: DIO_u8_DDRD_REG = Copy_u8PortDirection; break;
	}
}
void MDIO_voidWritePort(u8 Copy_u8PortNumber ,u8 Copy_u8PortValue)
{
	switch (Copy_u8PortNumber)
	{
	case DIO_u8_PORTA: DIO_u8_PORTA_REG = Copy_u8PortValue; break;
	case DIO_u8_PORTB: DIO_u8_PORTB_REG = Copy_u8PortValue; break;
	case DIO_u8_PORTC: DIO_u8_PORTC_REG = Copy_u8PortValue; break;
	case DIO_u8_PORTD: DIO_u8_PORTD_REG = Copy_u8PortValue; break;

	}
}

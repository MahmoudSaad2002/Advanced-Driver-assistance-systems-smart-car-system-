/*
 * DIO_Interface.h
 *
 *  Created on: 1 Aug 2024
 *      Author: ahmed
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
/***********MACRO FOR PORTS*********************/
#define DIO_u8_PORTA	0
#define DIO_u8_PORTB	1
#define DIO_u8_PORTC	2
#define DIO_u8_PORTD	3
/**********************************************/

/****************PIN NUMBER******************/
#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7
/********************************************/

/****************MACRO FOR PIN DIRECTION*******/
#define DIO_u8_PIN_INPUT	0
#define DIO_u8_PIN_OUTPUT	1
/**********************************************/

/************MACRO FOR PIN VALUE***************/
#define DIO_u8_LOW		0
#define DIO_u8_HIGH		1
/**********************************************/
/****************************************************************/
#define DIO_u8_PORT_INPUT             0x00
#define DIO_u8_PORT_OUTPUT            0xFF
/****************************************************************/

void MDIO_void_SetPinDirection(u8 A_u8_PortNumber, u8 A_u8_PinNumber, u8 A_u8_PinDirection);
void MDIO_void_WritePin(u8 A_u8_PortNumber, u8 A_u8_PinNumber, u8 A_u8_PinValue);
u8 MDIO_u8_ReadPin(u8 A_u8_PortNumber, u8 A_u8_PinNumber);
void MDIO_void_TogglePin(u8 A_u8_PortNumber, u8 A_u8_PinNumber);
void MDIO_voidSetPortDirection(u8 Copy_u8PortNumber ,u8 Copy_u8PortDirection);
void MDIO_voidWritePort(u8 Copy_u8PortNumber ,u8 Copy_u8PortValue);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */

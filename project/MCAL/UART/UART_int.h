/*
 * UART_int.h
 *
 *  Created on: August 20, 2024
 *      Author: Ahmed Gaballah
 */ 


#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void MUART_voidInit (void) ;

void MUART_voidSendData(u8 A_u8Data) ;

void MUART_voidSendString(u8* A_pu8Str) ;

void MUART_voidSendIntNumber(u32 A_u32Number) ;

u8 MUART_u8ReceiveData(void) ;

void MUART_voidReceiveString(u8 str[]) ;

u32 MUART_voidReciveIntNumber(void)  ;

#endif /* MCAL_UART_UART_INT_H_ */
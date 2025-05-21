/*
 * BUZZER_conf.h
 *
 *  Created on: August 22, 2024
 *      Author: Ahmed Gaballah
 */

#ifndef HAL_BUZZER_BUZZER_CONF_H
#define HAL_BUZZER_BUZZER_CONF_H
/**
 *Options of BUZZER_PORT are :
            *DIO_PORTA
			*DIO_PORTB
			*DIO_PORTC
			*DIO_PORTD

 *Options of BUZZER_PIN are :
            *DIO_PIN0
			*DIO_PIN1
			*DIO_PIN2
			*DIO_PIN3
			*DIO_PIN4
			*DIO_PIN5
			*DIO_PIN6
			*DIO_PIN7
*/


/**
 * connection of BUZZER 
*/
#define BUZZER_PORT    DIO_PORTC
#define BUZZER_PIN     DIO_PIN5

#endif /* HAL_BUZZER_BUZZER_CONF_H */

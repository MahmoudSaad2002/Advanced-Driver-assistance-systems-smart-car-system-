/*
 * LCD_conf.h
 *
 *  Created on: August 22, 2024
 *      Author: Ahmed Gaballah
 */
 
#ifndef HAL_LCD_LCD_CONF_H_
#define HAL_LCD_LCD_CONF_H_

/*
 *Connections of Data
     ** Options of PORTS :
	           *DIO_PORTA
			   *DIO_PORTB
			   *DIO_PORTC
			   *DIO_PORTD
			   
	 ** Options of PINS :
	           *DIO_PIN0
			   *DIO_PIN1
			   *DIO_PIN2
			   *DIO_PIN3
			   *DIO_PIN4
			   *DIO_PIN5
			   *DIO_PIN6
			   *DIO_PIN7
 */
 
/* Data */
#define LCD_DATA_PORT DIO_PORTA

/* Register Select */
#define LCD_RS_PORT   DIO_PORTA
#define LCD_RS_PIN    DIO_PIN1

/* Enable */
#define LCD_EN_PORT   DIO_PORTA
#define LCD_EN_PIN    DIO_PIN2

/* Read / write  */
#define LCD_RW_PORT   DIO_PORTA
#define LCD_RW_PIN    DIO_PIN3

/*
 *Select the mode of connections
    ** Options 
	      *EIGHT_BIT_CONNECTION
		  *FOUR_BIT_CONNECTION
		  
	** If you select EIGHT_BIT_CONNECTION
	        eight pins of port connected to  eight data pins
			
	** If you select EIGHT_BIT_CONNECTION
	        high nibble pins of port connected to  last four data pins		
 */
#define MODE       FOUR_BIT_CONNECTION

/** Base of number that be converted to string */
#define BASE   10

#endif /* HAL_LCD_LCD_CONF_H_ */

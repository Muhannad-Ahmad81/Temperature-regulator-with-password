/***********************************************************/
/*****************    Name : Mahmoud Moner *****************/
/*****************    Date : 16/8/2023     *****************/
/*****************    SWC  : DIO           *****************/
/***************** Virsion :  1.0          *****************/
/***********************************************************/  
#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/* Intial Directions for All Pins   */
/* Options : DIO_u8_INTIAL_OUTPUT 1
			 DIO_u8_INTIAL_INPUT  0 */
/* PORTA */			 
#define DIO_u8_PA0_INTIAL_DIRECTION                             DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PA1_INTIAL_DIRECTION                             DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PA2_INTIAL_DIRECTION                             DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PA3_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA4_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA5_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA6_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA7_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
/* PORTB */			                                             
#define DIO_u8_PB0_INTIAL_DIRECTION                             DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PB1_INTIAL_DIRECTION                             DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PB2_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB3_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB4_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB5_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB6_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB7_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
/* PORTC */			                                             
#define DIO_u8_PC0_INTIAL_DIRECTION                              DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PC1_INTIAL_DIRECTION                              DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PC2_INTIAL_DIRECTION                              DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PC3_INTIAL_DIRECTION                              DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PC4_INTIAL_DIRECTION                              DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PC5_INTIAL_DIRECTION                              DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PC6_INTIAL_DIRECTION                              DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PC7_INTIAL_DIRECTION                              DIO_u8_INTIAL_OUTPUT
/* PORTD */			                                             
#define DIO_u8_PD0_INTIAL_DIRECTION                             DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PD1_INTIAL_DIRECTION                             DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PD2_INTIAL_DIRECTION                             DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PD3_INTIAL_DIRECTION                             DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PD4_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PD5_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PD6_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PD7_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT

/* Intial Values for All Pins        */
/* Options : DIO_u8_OUTPUT_LOW     0
			 DIO_u8_OUTPUT_HIGH    1
			 DIO_u8_INPUT_FLOATING 0
			 DIO_u8_INPUT_PULLUP   1 */
/* PORTA */			 
#define DIO_u8_PA0_INTIAL_VALUE                                  DIO_u8_OUTPUT_LOW
#define DIO_u8_PA1_INTIAL_VALUE                                  DIO_u8_OUTPUT_LOW
#define DIO_u8_PA2_INTIAL_VALUE                                  DIO_u8_OUTPUT_LOW
#define DIO_u8_PA3_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA4_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA5_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA6_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA7_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
/* PORTB */			                                             
#define DIO_u8_PB0_INTIAL_VALUE                               	 DIO_u8_OUTPUT_LOW
#define DIO_u8_PB1_INTIAL_VALUE                                 DIO_u8_OUTPUT_LOW
#define DIO_u8_PB2_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB3_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB4_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB5_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB6_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB7_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
/* PORTC */			                                             
#define DIO_u8_PC0_INTIAL_VALUE                                   DIO_u8_OUTPUT_LOW
#define DIO_u8_PC1_INTIAL_VALUE                                   DIO_u8_OUTPUT_LOW
#define DIO_u8_PC2_INTIAL_VALUE                                   DIO_u8_OUTPUT_LOW
#define DIO_u8_PC3_INTIAL_VALUE                                   DIO_u8_OUTPUT_LOW
#define DIO_u8_PC4_INTIAL_VALUE                                   DIO_u8_OUTPUT_LOW
#define DIO_u8_PC5_INTIAL_VALUE                                   DIO_u8_OUTPUT_LOW
#define DIO_u8_PC6_INTIAL_VALUE                                   DIO_u8_OUTPUT_LOW
#define DIO_u8_PC7_INTIAL_VALUE                                   DIO_u8_OUTPUT_LOW
/* PORTD */			                                             
#define DIO_u8_PD0_INTIAL_VALUE                                  DIO_u8_OUTPUT_HIGH
#define DIO_u8_PD1_INTIAL_VALUE                                  DIO_u8_OUTPUT_HIGH
#define DIO_u8_PD2_INTIAL_VALUE                                  DIO_u8_OUTPUT_HIGH
#define DIO_u8_PD3_INTIAL_VALUE                                  DIO_u8_OUTPUT_HIGH
#define DIO_u8_PD4_INTIAL_VALUE                                  DIO_u8_INPUT_PULLUP
#define DIO_u8_PD5_INTIAL_VALUE                                  DIO_u8_INPUT_PULLUP
#define DIO_u8_PD6_INTIAL_VALUE                                  DIO_u8_INPUT_PULLUP
#define DIO_u8_PD7_INTIAL_VALUE                                  DIO_u8_INPUT_PULLUP

#endif

/***********************************************************/
/*****************    Name : Mahmoud Moner *****************/
/*****************    Date : 30/8/2023     *****************/
/*****************    SWC  : ADC           *****************/
/***************** Virsion :  1.0          *****************/
/***********************************************************/

#ifndef ADC_CONFIGER_H
#define ADC_CONFIGER_H

/* ADMUX */
#define ADC_u8_ADMUX_REFS1            7 
#define ADC_u8_ADMUX_REFS0            6 
#define ADC_u8_ADMUX_ADLAR            5 
#define ADC_u8_ADMUX_MUX4             4 
#define ADC_u8_ADMUX_MUX3             3 
#define ADC_u8_ADMUX_MUX2             2 
#define ADC_u8_ADMUX_MUX1             1 
#define ADC_u8_ADMUX_MUX0             0 
										
/* ADCSRA */                            
#define ADC_u8_ADCSRA_ADEN            7 // Using to enable ADC
#define ADC_u8_ADCSRA_ADSC            6 // Using to start convertion
#define ADC_u8_ADCSRA_ADATE           5 // Using to 1 --> auto treger
                                        //          0 -->singel conversion
#define ADC_u8_ADCSRA_ADIF            4 // Using to PIF
#define ADC_u8_ADCSRA_ADIE            3 // Using to PIE
#define ADC_u8_ADCSRA_ADPS2           2 // Using to CONTROL CLC DIVITION
#define ADC_u8_ADCSRA_ADPS1           1 //          CONTROL CLC DIVITION
#define ADC_u8_ADCSRA_ADPS0           0 //          CONTROL CLC DIVITION

#define ADC_u32_TIME_OUT_VALUE      50000

#define ADC_u32_NO_DIGITAL_VALUE     0xfff

#endif
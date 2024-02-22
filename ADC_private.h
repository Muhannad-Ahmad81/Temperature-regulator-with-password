/***********************************************************/
/*****************    Name : Mahmoud Moner *****************/
/*****************    Date : 30/8/2023     *****************/
/*****************    SWC  : ADC           *****************/
/***************** Virsion :  1.0          *****************/
/***********************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*ADC REGISTERS*/

#define ADC_u8_ADMUX_REG                 *((volatile u8*)0x27) //REFS1 REFS0             ADLAR                  MUX4 MUX3 MUX2 MUX1 MUX0
															   // 0      0   --> AREF       0 --> RIGHT ADJUST  USED TO CHOSE THE CANNEL
                                                               // 0      1   --> AVCC       1 --> LEFT ADJUSR   USED TO CHOSE THE CANNEL
                                                               // 1      0   --> NOT USED
                                                               // 1      1   --> 2.56 V


							             
#define ADC_u8_ADCSRA_REG                *((volatile u8*)0x26) //ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0
							             
#define ADC_u8_ADCL_REG                  *((volatile u8*)0x24) //ADC Data Register LOW Byte
							             
#define ADC_u8_ADCH_REG                  *((volatile u8*)0x25) //ADC Data Register High Byte

#define ADC_u16_ADCL_ADCH_MERG_REG       *((volatile u16*)0x24)// TO READ DATA FROM TWO REG IN ONE TIME
							             
#define ADC_u8_SFIOR_REG                 *((volatile u8*)0x50) //ADTS2 ADTS1 ADTS0 X X X X X
 







#endif
/***********************************************************/
/*****************    Name : Mahmoud Moner *****************/
/*****************    Date : 30/8/2023     *****************/
/*****************    SWC  : ADC           *****************/
/***************** Virsion :  1.0          *****************/
/***********************************************************/

/*LIB*/
#include "STD_TYPES.h" 
#include "BIT_MATH.h" 
#include "util/delay.h"
 
/*MCAL*/ 
#include "ADC_interface.h" 
#include "ADC_private.h" 
#include "ADC_configer.h"

static void (*ADC_pfNotfication) (u16) = NULL;

static u8 ADCGlobal_u8BusyFlag = 0;
 //////////////////////////////////////////////////////////////////////////////
void ADC_voidInit(void)
{
	/*  1- Select Vref = AVCC
		2- RIGHT ADJAST (10 BITS RESLOUTION)
		3- dISABLE AUTO TRIGER == Using Singel conversion mode	
		4-CLK devision of 64 = 8m/64
		5- Enable ADC
	*/
	
	//5- Enable ADC
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADEN);
	
	//1- Select Vref = AVCC
	CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS1);
	SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS0);
	
	//2- RIGHT ADJAST (10 BITS RESLOUTION)
	CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_ADLAR);
	
	//3- dISABLE AUTO TRIGER == Using Singel conversion mode	
	CLR_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADATE);
	
	//4-CLK devision of 64 = 8m/64
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADPS2);
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADPS1);
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADPS0);
	

}   
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
u8 ADC_u8GetDigitalValueNonBlocking(u8 Copy_u8ChannelINP, u16 *Copy_pu16DigitalValue)
{
	u8 Local_ErrorState = STD_TYPES_OK;
	u32 Local_u32Counter = 0;
	if(  (Copy_u8ChannelINP < 32) && (Copy_pu16DigitalValue != NULL) )
	{
		/*Clear MUX4.....0*/
		Copy_u8ChannelINP &= 0x07;
		ADC_u8_ADMUX_REG  &= 0xE0;
		/*Select the channel*/
		ADC_u8_ADMUX_REG |= Copy_u8ChannelINP;
		/*Start signal conversion*/
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADSC);
		/*Wating the flag to be 1*/
		while( (GET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADIF) ==  0) && (Local_u32Counter < ADC_u32_TIME_OUT_VALUE))
		{
			Local_u32Counter++;
		}
		if( GET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADIF) ==  1 )
		{
			/*Clear the flag by ablay one to it*/
			SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADIF );
			/*Reading the digital val*/
			*Copy_pu16DigitalValue = ADC_u16_ADCL_ADCH_MERG_REG;
		}
	}
	
	else
	{
		Local_ErrorState = STD_TYPES_NOK;
	}
	return Local_ErrorState;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
u8 ADC_u8GetDigitalValueAysyncrouns(u8 Copy_u8ChannelINP, void (*Copy_pfvoidNotfication)(u16) )
{
	u8 Local_ErrorState = STD_TYPES_OK;
	if(  (Copy_u8ChannelINP < 32) && (Copy_pfvoidNotfication != NULL) && ( ADCGlobal_u8BusyFlag == 0))
	{
		/*Set Flag to be busy*/
		ADCGlobal_u8BusyFlag = 1;
		/*Update Global Pointer To a Function*/
		ADC_pfNotfication = Copy_pfvoidNotfication;
		/*Enable ADC Interrupt*/
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADIE);		 
		/*Clear MUX4.....0*/
		Copy_u8ChannelINP &= 0x07;
		ADC_u8_ADMUX_REG  &= 0xE0;
		/*Select the channel*/
		ADC_u8_ADMUX_REG |= Copy_u8ChannelINP;
		/*Start signal conversion*/
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADSC);
	}
	else
	{
		Local_ErrorState = STD_TYPES_NOK;
	}
	return Local_ErrorState;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
u8 ADC_u8ReturnRegValue             (u16 *Copy_pu8Value)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu8Value != NULL)
	{
		/*Reading digital value of ADC form merg Reg */
		*Copy_pu8Value = ADC_u16_ADCL_ADCH_MERG_REG;
	}
	else
	{
	  Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	
	return Local_u8ErrorState;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/*ISR Prototype*/
void __vector_16(void)  __attribute__((signal));

void __vector_16(void) 
{
	if(ADC_pfNotfication != NULL)
	{
		/*Clear*/
		ADCGlobal_u8BusyFlag = 0;
		/*Clear PIE*/
		CLR_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADIE);	
		/*Calling Noti func*/		
		ADC_pfNotfication(ADC_u16_ADCL_ADCH_MERG_REG);
		
	}
}
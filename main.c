#include<util/delay.h>
#include <stdio.h>
#include "STD_TYPES.h"
#include "LCD_interface.h"

#include "KPD_interface.h"
#include "DIO_interface.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include <string.h>

 int res=0;
 u8 pass[5];
 u8 i=0;
 u8 tst;
 u16 digital,analog;
 int past=0;

int main(void)
{
    DIO_voidInit();
    ADC_voidInit();
    LCD_voidInit();


    u8 key=KPD_u8_KEY_NOT_PRESSED ;



    u8 kp=1;
    u8 sc=1;
    pass[0] = 2;


   while(1){


	   while(kp){

		   KPD_u8GetKeyState(&key);

		   if(key != '=' && key != KPD_u8_KEY_NOT_PRESSED && i<4){
			   if(sc){LCD_voidClearScreen(); sc=0;}
			   LCD_voidSendChar(key);
			   pass[i]=key;
			   tst=key;
			   i++;
			   key=KPD_u8_KEY_NOT_PRESSED;
		   }
		   else if(key=='='){
			   kp=0;
		   }

	   }

	  // res=Pass_intPassword(pass);

	   if(strcmp(pass, "1234") == 0){
		   LCD_voidClearScreen();
		   LCD_voidSendString("Correct",8);

		   break;
	   }
	   else{
		   LCD_voidClearScreen();
		   LCD_voidSendString("Incorrect",10);
		   kp=1;
		   i=0;
		   sc=1;
		   res=0;
	   }


   }



   while(1){

	   ADC_u8GetDigitalValueNonBlocking(ADC_u8_CHANNEL_4 ,& digital);
	   analog =(u16)(digital * 1500UL/1023);


	   if(digital !=past){
		   past=digital;
		   LCD_voidClearScreen();
		   LCD_voidWriteNum(analog/3);
	   }




   }


       return 0;
}

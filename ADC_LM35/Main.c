
#include "Dio.h"
#include"Macros.h"
#include"Std_Types.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/io.h>
#include<util/delay.h>
#include "LCD.h"

int main(void)
{
	Dio_vidSetPortDirection(Dio_PORTD,0xff);
	Dio_vidSetPortDirection(Dio_PORTA,0x00);
	u8 line[]="LMval = ";

	//setbit(ADMUX,6);//Vref same as VCC
	//clearbit(ADMUX,7);//Vref same as VCC
	//setbit(ADMUX,5);//left adjusted ADCH D9--D2 ADCL D1--D0
	//ADMUX=0b01100000;
	//setbit(ADCSRA,0);//prescaler 8000000/128 62.5kHz <200 KHz (valid option)
	//setbit(ADCSRA,1);//prescaler 8000000/128 62.5kHz <200 KHz (valid option)
	//setbit(ADCSRA,2);//prescaler 8000000/128 62.5kHz <200 KHz (valid option)
	//setbit(ADCSRA,7);//enable ADC
	//setbit(ADCSRA,6);//START Conversion (sc);
	ADCSRA=0X87;//10000111
	ADMUX=0b11100000;//11100000//internal VCC 2.56
	Lcd_vidInit();
    _delay_ms(100);
	while(1)
	{
		setbit(ADCSRA,6);//START Conversion (sc)
		while (getbit(ADCSRA,4)==0);//check if conversion done /pooling

		  PORTD=ADCH;
		  u16 val=PORTD;
		  u16 h=((val/100)%10);
		  u16 t=((val/10)%10);
		  u16 o=(val%10);
		  Lcd_vidGOTO(1,0);
		  Lcd_vidWriteString(line);
		  Lcd_vidWriteCharctr(h+'0');
		  Lcd_vidWriteCharctr(t+'0');
		  Lcd_vidWriteCharctr(o+'0');

	}


	return 0;
}

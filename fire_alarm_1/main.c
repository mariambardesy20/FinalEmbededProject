/*
 * fire_alarm_1.c
 *
 * Created: 1/20/2021 12:37:14 AM
 * Author : Vangard Vangard
 */ 


#include "lcd_driver.h"
#include "spi.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#define minAng 0
#define maxAng 180
#define minCount 250
#define maxCount 500
void ServoAngle(unsigned short angle);

int main(void)
{
   
	LCD_init();
	SPI_init(Slave);
	UART_init();
	DDRC|=((1<<4)|(1<<3));
	DDRD|=(1<<5);
	ICR1=4999;
	TCCR1A|=((1<<COM1A1)|(1<<WGM11));
	TCCR1B|=((1<<WGM12)|(1<<CS11)|(1<<CS10)|(1<<WGM13));
	OCR1A=50;
	  
    while (1) 
    {
	    if(SPI_Receive()==0xAA){
		 LCD_SendStringPos("fire!!",1,5);
		 	_delay_ms(500);
	    }
	 if(UART_RXChar()=='f'){
	  	ServoAngle(90);
	  	_delay_ms(500);
	 }
	 else {
   	 ServoAngle(0);
	 LCD_SendStringPos("normal",1,5);}
	 _delay_ms(500);
	LCD_clearDisplay();
		
    }

}
void ServoAngle(unsigned short angle){
OCR1A=(((maxCount-minCount)*(angle-minAng))/(maxAng-minAng))+minCount-1;
}

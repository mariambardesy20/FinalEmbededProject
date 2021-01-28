/*
 * fire_alarm_2.c
 *
 * Created: 1/20/2021 12:44:24 AM
 * Author : Vangard Vangard
 */ 


#include <avr/interrupt.h>
#include "UART.h"
#include "spi.h"
#include "ADC.h"
#include "lcd_driver.h"
#define minAng 0
#define maxAng 180
#define minCount 250
#define maxCount 500
void ServoAngle(unsigned short angle);
int main(void)
{
	 DDRC|=((1<<5)|(1<<6));
	 DDRD &=~(1<<2);
	 DDRC|=((1<<4)|(1<<3));
	 DDRD|=(1<<5);
     DDRA=0x0F;
    SPI_init(Master);
	SlaveEn();
	UART_init();   	
	 DDRB=0b11111111; 
	 TCCR0=0b01110101; 
	 TIMSK=0b00000000;
	 OCR0=255;	
	DDRC|=((1<<1)|(1<<2));
	DDRD|=(1<<5);
	ICR1=4999;
	TCCR1A|=((1<<COM1A1)|(1<<WGM11));
	TCCR1B|=((1<<WGM12)|(1<<CS11)|(1<<CS10)|(1<<WGM13));
	OCR1A=50;
char string[50];
	unsigned short temp =0;
	LCD_init();
	ADC_Init();
	char flag=0,flag2=0;
	while (1)
	{
		temp = ADC_Read(1);
		temp /= 4;
		itoa(temp,string,10);
		LCD_SendStringPos(string,1,1);
		_delay_ms(200);
		if (temp >= 70){
			LCD_SendStringPos("FIRE!!",1,5);
			if(flag==0){
			  SPI_Write(0xAA);
			  UART_TXChar('f');
			  flag=1;}
			  OCR0=190;
			  PORTC|=(1<<3);
			  PORTC&=~(1<<4);
			  PORTC^=(1<<5);
			  PORTC^=(1<<6);
			  ServoAngle(90);
			  flag2=0;
			_delay_ms(200);
		}
		
		else{
			flag=0;
			LCD_SendStringPos("Normal",1,5);
			if(flag2==0){
				SPI_Write(0x00);
				UART_TXChar('l');
			flag2=1;}
			 PORTC&=~(1<<3);
			 PORTC&=~(1<<4);
			 PORTC&=~(1<<5);
			 PORTC&=~(1<<6);
			 ServoAngle(0);
			_delay_ms(200);
		}
	LCD_clearDisplay();		
	}
}
void ServoAngle(unsigned short angle){
	OCR1A=(((maxCount-minCount)*(angle-minAng))/(maxAng-minAng))+minCount-1;
}

/*
 * UART.c
 *
 * Created: 1/1/2021 5:39:31 PM
 *  Author: Vangard Vangard
 */ 
#include "UART.h"
void UART_init(){
	UCSRB |= ((1<<RXEN)|(1<<TXEN));
	UCSRC |=((1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0));
	UBRRL =MyUBRR;
	UBRRH =(MyUBRR>>8);
	}
void UART_TXChar(char data){
	while(!((UCSRA>>UDRE)&1));
	UDR=data;
}
char UART_RXChar(){
	while(!((UCSRA>>RXC)&1));
	return UDR;
}
void UART_TXString(char* string){
	unsigned char i=0;
	while (string[i]!='\0'){
		UART_TXChar(string[i]);
		i++;
	}
	
	
}
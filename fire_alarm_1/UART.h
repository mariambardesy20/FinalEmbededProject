/*
 * UART.h
 *
 * Created: 1/1/2021 5:39:44 PM
 *  Author: Vangard Vangard
 */ 


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
#define F_CPU 16000000UL
#define BaudRate 9600
#define DoubleSpeed 0
#if (DoubleSpeed==0)
   #define MyUBRR ((F_CPU/(16UL*BaudRate))-1)
#else
   #define MyUBRR ((F_CPU/(8UL*BaudRate))-1)
#endif
void UART_init();
void UART_TXChar(char data);
char UART_RXChar();
void UART_TXString(char* string);

#endif /* UART_H_ */
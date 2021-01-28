/*
 * lcd_driver.c
 *
 *  Created on: Nov 20, 2020
 *      Author: Vangard Vangard
 */
#include<stdio.h>
#include<stdlib.h>
#include<avr/io.h>
#include"macros.h"
#include "lcd_driver.h"
void LCD_clearDisplay(void){

	LCD_DATA_PORT =0X00;
	setbit(LCD_DATA_PORT,LCD_DB0_PIN);
	LCD_CONTROL_PORT &= ~(1<<LCD_RS_PIN);
	LCD_CONTROL_PORT &= ~(1<<LCD_RW_PIN);
}
void LCD_enable(void){

	setbit(LCD_CONTROL_PORT,LCD_E_PIN);
}
void LCD_disable(void){

	clearbit(LCD_CONTROL_PORT,LCD_E_PIN);
}
void LCD_writeCommand(Unit8 hex){
	clearbit(LCD_CONTROL_PORT,LCD_RW_PIN);
	_delay_ms(1);
	LCD_enable();
	_delay_ms(1);
    LCD_DATA_PORT= hex;
	LCD_disable();

}
void LCD_init(void){
	LCD_DATA_DDR=0x0F;
	LCD_CONTROL_DDR=0xFF;
	_delay_ms(40);
	LCD_writeCommand(0x20);
	LCD_writeCommand(0x20);
	LCD_writeCommand(0x80);
	_delay_ms(1);
	LCD_writeCommand(0x00);
	LCD_writeCommand(0xF0);
	_delay_ms(1);
	LCD_writeCommand(0x00);
	LCD_writeCommand(0x10);
	_delay_ms(2);
}
void LCD_writeChar(Unit8 c){
	clearbit(LCD_CONTROL_PORT,LCD_RW_PIN);
	setbit(LCD_CONTROL_PORT,LCD_RS_PIN);
	LCD_writeCommand(c);
	_delay_ms(1);
	LCD_enable();
	_delay_ms(1);
	LCD_DATA_PORT=((c<<4)&0xF0);
	_delay_ms(1);
	LCD_disable();
}
void LCD_SendString(Sint8* string){
	Unit8 i = 0;
	while (string[i] != '\0')
	{
		LCD_writeChar(string[i]);
		i++;
	}
}
void LCD_SendStringPos(Sint8* string,Unit8 line ,Unit8 pos){
	switch (line)
	{
		case 1:
		LCD_writeCommand((0x80 | (pos&0x0F))&0xF0);
		LCD_writeCommand((0x80 | (pos&0x0F))<<4);
		LCD_SendString(string);
		break;
		case 2:
		LCD_writeCommand((0xC0 | (pos&0x0F))&0xF0);
		LCD_writeCommand((0xC0 | (pos&0x0F))<<4);
		LCD_SendString(string);
		break;
	}
}
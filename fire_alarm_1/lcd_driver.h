/*
 * lcd_driver.h
 *
 *  Created on: Nov 20, 2020
 *      Author: Vangard Vangard
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_
#include<stdio.h>
#include<stdlib.h>
#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include"macros.h"
#include"lcd_config.h"
typedef unsigned char Unit8;
typedef char Sint8;
void LCD_clearDisplay(void);
void LCD_init(void);
void LCD_writeCommand(unsigned char hex);
void LCD_disable(void);
void LCD_enable(void);
void LCD_SendString(Sint8* string);
void LCD_SendStringPos(Sint8* string,Unit8 line ,Unit8 pos);
#endif /* LCD_DRIVER_H_ */

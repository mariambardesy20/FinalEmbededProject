/*
 * spi.h
 *
 * Created: 1/8/2021 4:56:42 PM
 *  Author: Vangard Vangard
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7
typedef enum{Master=0,Slave}SPI_StatusTypes;
void SPI_init(SPI_StatusTypes status);
unsigned char SPI_TxRx(unsigned char data);

char SPI_Receive();
void SPI_Write(char data);



#endif /* SPI_H_ */
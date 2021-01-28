/*
 * spi.h
 *
 * Created: 1/8/2021 4:56:42 PM
 *  Author: Vangard Vangard
 */ 


#ifndef SPI_H_
#define SPI_H_
#define SlaveEn() (PORTB &=~(1<<SS))
#define SlaveDIS() (PORTB|=(1<<SS))
#include <avr/io.h>
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7
typedef struct{
	unsigned char SSPR0:1;
	unsigned char SSPR1:1;
	unsigned char SCPHA:1;
	unsigned char SCPOL:1;
	unsigned char SMSTR:1;
	unsigned char SDORD:1;
	unsigned char SSPE:1;
	unsigned char SSPIE:1;
}SPI_SPCRBITS;
typedef struct{
	unsigned char SSPI2X:1;
	unsigned char SRES0:1;
	unsigned char SRES1:1;
	unsigned char SRES2:1;
	unsigned char SRES3:1;
	unsigned char SRES4:1;
	unsigned char SSPIF:1;
	unsigned char SWCOL:1;
}SPI_SPSRBITS;
typedef struct{
    SPI_SPCRBITS SPI_SPCR;
	SPI_SPSRBITS  SPI_SPSR;
	unsigned char  SPI_SPDR ;
}SPI_REGTYPES;

#define SPI ((volatile SPI_REGTYPES*)0x2D)
	
	
	
typedef enum{Master=0,Slave}SPI_StatusTypes;
void SPI_init(SPI_StatusTypes status);
unsigned char SPI_TxRx(unsigned char data);
char SPI_Receive();
void SPI_Write(char data);


#endif /* SPI_H_ */
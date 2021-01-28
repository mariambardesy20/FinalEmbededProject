/*
 * spi.c
 *
 * Created: 1/8/2021 4:56:31 PM
 *  Author: Vangard Vangard
 */
#include "spi.h"
void SPI_init(SPI_StatusTypes status){
	
	switch (status){
	case Master:
	  DDRB|=((1<<SCK)|(1<<MOSI)|(1<<SS));
	  DDRB&=~(1<<MISO);
	  SPCR|= ((1<<SPE)|(1<<MSTR));
	break;
	case Slave:
	  DDRB|=((1<<MISO));
	  DDRB&=~((1<<SCK)|(1<<MOSI)|(1<<SS));
	  SPCR|= (1<<SPE);
	break;
	}
	
}
unsigned char SPI_TxRx(unsigned char data){
	SPDR=data;
	while(!((SPSR>>SPIF)&1));
	return SPDR;
	
}char SPI_Receive()
{
	while(!(SPSR & (1<<SPIF)));
	return(SPDR);
}
void SPI_Write(char data)
{
	
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	
}
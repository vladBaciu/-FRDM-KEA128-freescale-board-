/*
 * UART.c
 *
 *  Created on: Apr 28, 2018
 *      Author: Vlad
 */

#include "UART.h"
#include "derivative.h"

#define UART0_select_shift 7
#define UART0_enable_shift 20
#define Tx_enable_shift  3
#define Rx_enable_shift  2
#define Rx_interrupt_shift 5
#define RDRF_flag 5
#define TDRF_flag 7


void UART_init()
{
	SIM_PINSEL0 &= 0<<UART0_select_shift;             // en uart0  PB0 , PB1  | on board PTB0 -rx and PTB1 - tx
	SIM_SCGC |= 1<<UART0_enable_shift;                // en UART0 bus clock
	UART0_BDH = 0;
	UART0_BDL = 128;	                                   //bus_freq/ 16* BDL = baud_rate
														  // bus_freq=core_freq/2;
	UART0_C1  = 0;
	UART0_C2  |= (1<<Tx_enable_shift) | (1<<Rx_enable_shift) | (1<<Rx_interrupt_shift);   // enable tx,rx,rie
}

char UART_rx()
{
	while( (UART0_S1 & (1<<RDRF_flag) ) ==0 );           //wait RDRF flag to become 1
	char data_rx=UART0_D;

	return data_rx;
}

void UART_tx(char n)
{
	while ( (UART0_S1 & (1<<TDRF_flag))==0);                    // wait transmit buffer to be empty
	UART0_D=n;
}
void UART_string(char *str)
{
	unsigned int i=0;
	while(str[i] != '\0')
		  UART_tx(str[i++]);
	 UART_tx(13);

}

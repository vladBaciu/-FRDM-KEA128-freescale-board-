/*
 * UART.h
 *
 *  Created on: Apr 28, 2018
 *      Author: Vlad
 */

#ifndef UART_H_
#define UART_H_

void UART_init(void);
char UART_rx();
void UART_tx(char transmit);
void UART_string(char *str);
#endif /* UART_H_ */

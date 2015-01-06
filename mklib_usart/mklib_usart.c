/*
 * usart.c
 *
 *  Created on: 22-06-2013
 *      Author: Michal Kaptur
 *       Email: kaptur.michal at gmail dot com
 * 
 */

#include "mklib_usart.h"
#include <avr/io.h>
#include <stdio.h>

static FILE stdio_usart = FDEV_SETUP_STREAM(USART_putchar, NULL, _FDEV_SETUP_WRITE);

uint8_t USART_init(uint32_t baudrate, uint8_t  rx_enable, uint8_t tx_enable, uint8_t rx_int_enable, uint8_t tx_int_enable)
{
	if (tx_enable == 1) UCSRB |= (1<<TXEN);
		else UCSRB &= ~(1<<TXEN);

	if (rx_enable == 1) UCSRB |= (1<<RXEN);
		else UCSRB &= ~(1<<RXEN);

	uint32_t temp = (((F_CPU / (baudrate * 16UL))) - 1);

	UBRRL = temp;
	UBRRH = (temp>>8);

	if (rx_int_enable == 1) UCSRB |= (1<<RXCIE);
		else UCSRB &= ~(1<<RXCIE);

	if (tx_int_enable == 1) UCSRB |= (1<<TXCIE);
		else UCSRB &= ~(1<<TXCIE);

	return 0;
}

uint8_t USART_putchar(uint8_t c, FILE *stream)
{
	while (!(UCSRA & (1<<UDRE)));
    if (c == '\n') USART_putchar('\r', stream);
	while (!(UCSRA & (1<<UDRE)));
	UDR = c;
    return 0;
}

uint8_t USART_stdout_redirect()
{
	stdout = &stdio_usart;
	return 0;
}

uint8_t USART_getchar()
{
	uint8_t temp;
	UCSRB &= ~(1<<RXCIE);
	while (!(UCSRA & (1<<RXC)));
	UCSRB |= (1<<RXCIE);
	temp = UDR;
	return temp;
}

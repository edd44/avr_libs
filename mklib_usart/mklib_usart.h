/*
 * usart.h
 *
 *  Created on: 22-06-2013
 *      Author: Michal Kaptur
 *       Email: kaptur.michal at gmail dot com
 * 
 */

#ifndef MKLIB_USART_H
#define MKLIB_USART_H
 
 
#include <avr/io.h>
#include <stdio.h>

#define RX_ENABLE 1
#define RX_DISABLE 0
#define TX_ENABLE 1
#define TX_DISABLE 0
#define RX_INT_ENABLE 1
#define RX_INT_DISABLE 0
#define TX_INT_ENABLE 1
#define TX_INT_DISABLE 0

uint8_t USART_init(uint32_t baudrate, uint8_t rx_enable, uint8_t tx_enable, uint8_t rx_int_enable, uint8_t tx_int_enable);
uint8_t USART_putchar(uint8_t c, FILE *stream);
uint8_t USART_stdout_redirect();
uint8_t USART_getchar();


#endif //MKLIB_USART_H

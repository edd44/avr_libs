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



int USART_init(unsigned int baudrate, unsigned char  rx_enable, unsigned char tx_enable, unsigned char rx_int_enable, unsigned char tx_int_enable);
int USART_putchar(char c, FILE *stream);
int USART_stdout_redirect();
char USART_getchar();


#endif //MKLIB_USART_H
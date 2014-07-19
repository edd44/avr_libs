/*
 * mklib_1wire.h
 *
 *  Created on: 27-06-2013
 *      Author: Michal Kaptur
 *       Email: kaptur.michal at gmail dot com
 * 
 */
#ifndef MKLIB_1WIRE_H
#define MKLIB_1WIRE_H
 
#include <avr/io.h>



//obsolete!-----------------
#define OneW_PORT PORTA
#define OneW_PIN PINA
#define OneW_DDR DDRA
#define OneW_PIN_NR 1
//--------------------------
#define OneW_SET OneW_DDR&=~(1<<OneW_PIN_NR)
#define OneW_CLEAR OneW_DDR|=(1<<OneW_PIN_NR)

//do wywalenia------------------------------------------------------
#define WE 1
#define PORT_1Wire PINA
#define SET_1wire DDRA&=~_BV(WE)
#define CLEAR_1wire DDRA|=_BV(WE)


#define _1WPORT	A
#define _1WPIN	A
#define _1WSLOT	(1<<1)
#define _1W_WE	{ (PINA & _1WSLOT); }

#define _1W_SET_0()	{ DDRA |= 0x02; }	//PB.0 jako wyjœcie,
										//PB.0 = 0, wiêc stan na linii wynosi 0
#define _1W_SET_1()	{ DDRA &= 0xFD;}	//PB.0 jako wejœcie,
										//stan 1 pochodzi z rezystora PullUp
//do wywalenia------------------------------------------------------

int OneW_reset();
//char OneW_read_bit();
//int OneW_send_bit(char bit);
int OneW_send_byte(char byte);
char OneW_read_byte(void);


#endif //MKLIB_1WIRE_H

/*
 * ds18b20.h
 *
 *  Created on: 07-07-2013
 *      Author: edd
 */
#include <mklib_1wire.h>
#include <stdio.h>
#include <util/delay.h>

int DS18B20_get_temp(unsigned char *address, signed char *temp_int,unsigned int *temp_fract);
int DS18B20_get_temp_noaddress(signed char *temp_int,unsigned int *temp_fract);
int DS18B20_read_address(unsigned char *array);

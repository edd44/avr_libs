/*
 * ds18b20.c
 *
 *  Created on: 07-07-2013
 *      Author: edd
 */
#include "mklib_ds18b20.h"
#include "mklib_1wire.h"

int DS18B20_get_temp_noaddress(signed char *temp_int,unsigned int *temp_fract)
{
	//if dla reseta dodaj
	if (OneW_reset() != 0) return 1;
	OneW_send_byte(0xCC);
	OneW_send_byte(0x44);
	_delay_ms(750);

	OneW_reset();
	OneW_send_byte(0xCC);
	OneW_send_byte(0xBE);

	unsigned int templ;
	signed char temph;

	templ = OneW_read_byte();
	temph = OneW_read_byte();

	temph &= 0x07;
	temph = ((temph<<4) | (templ>>4));
	templ = (templ & 0xF);
	templ *= (62.5);

	*temp_int = temph;
	*temp_fract = templ;


	return 0;
}

int DS18B20_read_address(unsigned char *array)
{
	if (OneW_reset() != 0) return 1;
	OneW_send_byte(0x33); //read ROM
	for (int i = 0; i<8; i++)
	{
		array[i] = OneW_read_byte();
	}
	return 0;
}

int DS18B20_get_temp(unsigned char *address, signed char *temp_int,unsigned int *temp_fract)
{
	//if dla reseta dodaj
	if (OneW_reset() != 0) return 1;
	OneW_send_byte(0x55);
	for (int i = 0; i<8; i++)
	{
		OneW_send_byte(address[i]);
	}
	OneW_send_byte(0x44);
	_delay_ms(750);



	OneW_reset();
	OneW_send_byte(0x55);
		for (int i = 0; i<8; i++)
		{
			OneW_send_byte(address[i]);
		}
	OneW_send_byte(0xBE);

	unsigned int templ;
	signed char temph;

	templ = OneW_read_byte();
	temph = OneW_read_byte();

	temph &= 0x07;
	temph = ((temph<<4) | (templ>>4));
	templ = (templ & 0xF);
	templ *= (62.5);

	*temp_int = temph;
	*temp_fract = templ;


	return 0;
	return 0;
}

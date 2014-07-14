#include "mklib_1wire.h"
#include <stdio.h>
#include <util/delay.h>

//dupa

int OneW_reset()
{
	OneW_CLEAR;
	_delay_us(490);
	OneW_SET;
	_delay_us(65);
	if (PINA&=(1<<OneW_PIN_NR) == 0)
		return 1;
	_delay_us(425);
	return 0;
}

char OneW_read_bit()
{
	char _bit=0;

	_1W_SET_0();	//ustaw 0
	_delay_us(1);
	_1W_SET_1();	//zwolnij magistralê, stan H z rezystora PullUp
	_delay_us(14);
	_bit = (_1W_WE);		//zwróæ wartoœæ PinB.0, 1 lub 0
	_delay_us(60);
	return _bit;
}

int OneW_send_bit(char bit)
{
	CLEAR_1wire;
	_delay_us(5);
	if (bit == 1)
		SET_1wire;
	_delay_us(80);
	SET_1wire;

	return 0;
}

int OneW_send_byte(char byte)
{
	char temp;
	for (int x = 0; x<8; x++)
	{
		temp = (byte>>x);
		temp &= 0x1;
		OneW_send_bit(temp);
	}
	_delay_us(100);
	return 0;
}

char OneW_read_byte(void)
{
	uint8_t i;
	uint8_t data=0;

	for(i=0x01; i!=0; i<<=1)	//za ka¿dym obiegiem, przesuñ jedynkê w lewo odpowiada
	{							//pozycjom zczytanej wartoœci (czytamy od LSB do MSB)
		if( OneW_read_bit() )		//jeœli _1WireReadSlot() odczyta³ 1
			data |= i;			//umieœæ 1 na odpowiedniej pozycji
	}
	return data;
}

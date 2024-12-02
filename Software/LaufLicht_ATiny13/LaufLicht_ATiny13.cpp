/*
 * LaufLicht_ATiny13.cpp
 *
 * einfaches Lauflicht
 *
 * Created: 20.11.2021 10:14:28
 * Author : Michael
 *
 *************************************************** 
 *  Copyright (c) 2021 Michael Zimmermann <http://www.kruemelsoft.privat.t-online.de>
 *  All rights reserved.
 *
 *  LICENSE
 *  -------
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************
 */ 

#define F_CPU 1200000UL  // default fuses sind 9.6Mhz internal Oszi und CLKDIV 8 => 1.2Mhz
#include <avr/io.h>
#include <util/delay.h>

#define LED_MAX			5
#define TIME_ON_MS		100
#define TIME_DELAY_MS	200

int main(void)
{

	// Alle verwendeten Pins auf OUTPUT setzen
	DDRB	=  0b00011111; // alles Ausgänge, keine internen PullUp erforderlich
	PORTB   =  0b00000000;

	while (1)
	{
		for(int i = 0; i < LED_MAX; i++)
		{
			PORTB |= (1 << i);
			_delay_ms(TIME_ON_MS);
			PORTB &= ~(1 << i);
			_delay_ms(TIME_DELAY_MS);
		}
	}
	return 0;
}

/*
 * Blitz_Blinker.cpp
 *
 * Blitzlicht und Warnblinker
 * (entspricht der Elektronik des FotoMichel:
 *  Blitzelektronik für den fotografierenden Michael)
 *
 * used on Lichtcomputer with ATtiny13
 * Fuses for ATtiny13: L = 0x6A, H = 0xFF (default)
 * 
 * Created: 30.11.2024 11:00
 * Author : Michael
 *
 *************************************************** 
 *  Copyright (c) 2024 Michael Zimmermann <https://kruemelsoft.hier-im-netz.de/>
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

#define F_CPU 1200000UL  // default fuses are 9.6Mhz internal Oszi and CLKDIV 8 => 1.2Mhz
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLITZ_1		PB0 // A Pin5: Led-Blitzlicht
#define BLITZ_2		PB1 // A Pin6: Led-Blitzlicht
#define SET_ON		PB3 // E Pin2: 0 = Blitzlicht einschalten
#define BLINKER		PB4 // A Pin3: Warnblinker (daueraktiv)

uint8_t iOutputState(0);
uint8_t iTimerCount(0);

//*************************************
// initialize Timer
void init_timer()
{
	// no PWM Mode
	TCCR0A = 0;
	// Prescaler 8 -> leads to 586 Hz
	TCCR0B = (1 << CS01);
	// Trigger an interrupt on overflow
	TIMSK0 = (1 << TOIE0);
	// enable interrupts
	sei();
}

// Timer Interrupt
ISR(TIM0_OVF_vect)
{
	++iTimerCount;
	
	if(!iTimerCount)
		iOutputState = !iOutputState;
		
	if(iOutputState)
		PORTB |= (1 << BLINKER);
	else
		PORTB &= ~(1 << BLINKER);
}
//*************************************

int main(void)
{
  // set to Output
	DDRB   =  (1 << BLITZ_1) | (1 << BLITZ_2) | (1 << BLINKER);
  // activate internal PullUp
	PORTB |=  (1 << SET_ON);

	iOutputState = 0;
	iTimerCount = 0;

  while (1)
  {
		if(bit_is_clear(PINB, SET_ON))
		{
			PORTB |= (1 << BLITZ_1);
			_delay_ms(1);
			PORTB &= ~(1 << BLITZ_1);

			_delay_ms(250);		// nach 250ms blitzt auch der zweite :-)

			PORTB |= (1 << BLITZ_2);
			_delay_ms(1);
			PORTB &= ~(1 << BLITZ_2);

			_delay_ms(2000);	// 2 Sekunden Pause
		}
  }
  return 0;
}

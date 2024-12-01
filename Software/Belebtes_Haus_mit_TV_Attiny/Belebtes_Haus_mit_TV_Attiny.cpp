/*
 * Belebtes_Haus_mit_TV_Attiny.cpp
 * 
 * Created: 11.10.2018 09:58:15
 * Author : Michael
 *
 *************************************************** 
 *  Copyright (c) 2018 Michael Zimmermann <http://www.kruemelsoft.privat.t-online.de>
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
 * https://www.herberts-n-projekt.de/basteleien-1/belebtes-haus/
 ****************************************************
 *      LED       Funktion
 * PB0  warmweiss Fernsehzimmer
 * PB1  kaltweiss Fernseher
 * PB2  warmweiss beliebig
 * PB3  warmweiss beliebig
 * PB4  warmweiss beliebig
 * 
 * zur Nutzung mit dem "Lichtcomputer_LED" ist J1/J2 auf die alternative Lˆtjumperstellung zu ‰ndern.
 *
 *  Simulation "belebtes Haus f¸r die Modellbahn"
 *  Version "Flimmern nur wenn die LED_0_TV_ROOM an ist"
 */

#define F_CPU 1200000UL  // default fuses sind 9.6Mhz internal Oszi und CLKDIV 8 => 1.2Mhz
#include <avr/io.h>

#include "..\..\Arduino2ATtiny45.h"

/* PWM-methods for PB1 *****************************************************/
void pwm_setup()
{
	// Set Timer 0 prescaler to clock/8. At 9.6 MHz this is 1.2 MHz.
	TCCR0B |= (1 << CS01) | (1 << CS00);

	// Set to 'Fast PWM' mode
	TCCR0A |= (1 << WGM01) | (1 << WGM00);

	// Clear OC0B output on compare match, upwards counting.
	TCCR0A |= (1 << COM0B1);
}

void pwm_write(uint8_t ui8val)
{
	OCR0B = ui8val;
}
/* end of PWM-methods for PB1 */

#define LED_0_TV_ROOM	PB0
#define LED_1_TV			PB1
#define LED_2					PB2
#define LED_3					PB3
#define LED_4					PB4

// LED Pins f¸r das normale Blinken deklarieren
uint8_t leds[] = {LED_4, LED_3, LED_2, LED_0_TV_ROOM};
// LED Blinktakt in Millisekunden f¸r diese Pins
unsigned long ledtakt[] = {6000, 8800, 13000, 20000};
// Variablen zum Merken von millis()-Zeiten beim Schalten/Blinken
unsigned long ledtime[sizeof(leds)];

unsigned long flimmerStart, flimmerEnd; // Anfangs- und Endzeiten f¸r das Flimmern
	
bool milliSekundenTakt(unsigned long dauer, unsigned long &alterWert)
{
	// Parameter "dauer": Dauer einer Blinkphase (an bzw. aus)
	// Parameter "alterWert": Variable zum Speichern des millis() Timers
	// R¸ckgabewert: true wenn die Zeit bis zum n‰chsten Umschalten abgelaufen ist, sonst false
	if ((millis() - alterWert) < dauer)
		return false;
	while ((millis() - alterWert) >= dauer)
		alterWert += dauer;
	return true;
}

void blinkenImTakt()
{
	// Alle gleichm‰ﬂig blinkenden LEDs in ihrem eigenen Takt blinken lassen
	for (uint8_t i = 0; i < sizeof(leds); i++) // alle LEDs in einer Schleife durchgehen
	{
		if (milliSekundenTakt(ledtakt[i],ledtime[i])) // Takt f¸r diese LED abgelaufen?
		{
			digitalWrite(leds[i], !digitalRead(leds[i]));							// wenn ja ==> Umschalten
			if ((leds[i] == LED_0_TV_ROOM) && digitalRead(leds[i]))		// LED_0_TV_ROOM wurde gerade eingeschaltet
			{
				flimmerStart = millis() +  2000; // Anfangszeit f¸r das Flimmern setzen
				flimmerEnd   = millis() + 15000; // Endzeit f¸r das Flimmern setzen
			}
		}
	}
}

void flimmernPwmPin()
{
	// Die flimmernde LED im Zufallsmodus flimmern lassen
	static unsigned long alterWert;
	static unsigned int flimmerDauer = 200;
	static uint8_t flimmerHelligkeit;
	if (milliSekundenTakt(flimmerDauer,alterWert)) // Takt abgelaufen?
	{
		flimmerDauer = 1 + random(200); // neue Flimmerdauer als Zufallswert
		if (millis() > flimmerStart && millis() < flimmerEnd)
			flimmerHelligkeit = random(256); // neue Flimmerhelligkeit als Zufallswert
		else
			flimmerHelligkeit = 0; // Flimmern aus wenn falsche Zeit zum Flimmern
		pwm_write(flimmerHelligkeit);
	}
}

int main(void)
{
	// Alle verwendeten Pins auf OUTPUT setzen
	DDRB   =  (1 << LED_0_TV_ROOM) | (1 << LED_1_TV) | (1 << LED_2) | (1 << LED_3) | (1 << LED_4);

	timer_setup();
	pwm_setup();

  while (1) 
  {
		blinkenImTakt();
		flimmernPwmPin();
  }
		
	return 0;
}


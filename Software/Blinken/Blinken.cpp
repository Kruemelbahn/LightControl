/*
 * Blinken.cpp
 *
 * Created: 16.01.2017 19:56:57
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
 */ 

#define F_CPU 1200000UL  // default fuses sind 9.6Mhz internal Oszi und CLKDIV 8 => 1.2Mhz
#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB0  //LED an PB0

int main(void) {

  DDRB |= (1 << LED_PIN);  //Als Ausgang konfigurieren
  PORTB = (1 << LED_PIN);

  while (1) {
    PORTB |= (1 << LED_PIN);
    _delay_ms(500);
    PORTB &= ~(1 << LED_PIN);
    _delay_ms(500);
  }
  return 0;
}

/*  5fach-Blinken mit unterschiedlichen Takten */

// LED Pins für das normale Blinken deklarieren
byte leds[]             = {  4,   3,   2,   1,   0};
// LED Blinktakt in Millisekunden für diese Pins
unsigned long ledtakt[] = {400, 450, 500, 550, 600};
// Variablen zum Merken von millis()-Zeiten beim Schalten/Blinken
unsigned long ledtime[sizeof(leds)];

void setup() {
  // Alle verwendeten Pins auf OUTPUT setzen
  for (unsigned int i = 0; i < sizeof(leds); i++)
    pinMode(leds[i], OUTPUT);
}

boolean milliSekundenTakt(unsigned long dauer, unsigned long &alterWert) {
// Parameter "dauer": Dauer einer Blinkphase (an bzw. aus)
// Parameter "alterWert": Variable zum Speichern des millis() Timers
// Rückgabewert: true wenn die Zeit bis zum nächsten Umschalten abgelaufen ist, sonst false
  if ((millis() - alterWert) < dauer)
    return false;
  while ((millis() - alterWert) >= dauer)
    alterWert += dauer;
  return true;  
}

void blinkenImTakt() {
  // Alle gleichmäßig blinkenden LEDs in ihrem eigenen Takt blinken lassen  
  for (unsigned int i = 0; i < sizeof(leds); i++) // alle LEDs in einer Schleife durchgehen
  {
    if (milliSekundenTakt(ledtakt[i], ledtime[i])) // Takt für diese LED abgelaufen?
      digitalWrite(leds[i], !digitalRead(leds[i]));  // wenn ja ==> Umschalten
  }
}


void loop() {
  blinkenImTakt();
}

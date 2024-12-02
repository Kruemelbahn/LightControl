// *************************************************************************************************************
// Einsatz-Fahrzeug EF1 für ATtiny 13/45/85
// -------------------------------------------------------------------------------------------------------------
// Port 0 / 1 / 2 : Blinklicht 2 Hz bis 5 Hz mit High-Low-Verhältnis 1:3 (Blaulicht)
// Port 3 / 4     : Blinker 1,5 Hz +/- 0,5 Hz gemäß STVZO § 54 Fahrtrichtungsanzeiger,
//                  die relative Hellzeit der Blinkleuchten muss 30 % bis 80 % betragen
//
// zur Nutzung mit dem "Lichtcomputer_LED" ist J1/J2 auf die alternative Lötjumperstellung zu ändern.
//
// -------------------------------------------------------------------------------------------------------------
// Version 1.00, 26.11.2014, Prinziptest
// Version 1.10, 27.11.2014, Blinkfrequenzen an STVZO angepasst
// *************************************************************************************************************
// https://www.stummiforum.de/t92344f21-Belebtes-Haus-zum-Schn-ppchenpreis-11.html#msg1311574
// https://www.stummiforum.de/t154160f21-Blaulicht-Elektronik.html#msg1755431
// *************************************************************************************************************

 
void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}
 
void loop()  {
  if( ((millis()/115) % 4) == 0) {   // Blinklicht ca. 2 Hz, Verhältnis 1:3 (Blau-/Gelblicht)
    digitalWrite(0, HIGH);
  }
  else {
    digitalWrite(0, LOW); 
  }
  if( ((millis()/120) % 4) == 0) {   // Blinklicht ca. 2 Hz, Verhältnis 1:3 (Blau-/Gelblicht)
    digitalWrite(1, HIGH);
  }
  else {
    digitalWrite(1, LOW); 
  }
  if( ((millis()/125) % 4) == 0) {   // Blinklicht ca. 2 Hz, Verhältnis 1:3 (Blau-/Gelblicht)
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW); 
  }
  if( ((millis()/510) % 2) == 0) {   // Blinklicht ca. 1 Hz, Verhältnis 1:1 (Fahrtrichtungsanzeiger)
    digitalWrite(3, LOW);            // Wechselblinker: für einen der Ports LOW und HIGH vertauschen
    digitalWrite(4, LOW); 
  }
  else {
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH);
  }
}
// *************************************************************************************************************

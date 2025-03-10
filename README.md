# LightControl

...ist eine kleine Sammlung von Lichtsteuerungen (mit analoger Ansteuerung) auf meiner Modellbahn.

Nachfolgende Softwarepakete stehen unter [Software](https://github.com/Kruemelbahn/lightControl/tree/main/Software) zur Verfügung
- auf Arduino-Basis, kompiliert für ATtiny13 (für die Arduino-IDE wird das Board [MicroCore](https://github.com/MCUdude/MicroCore) verwendet):
  - [Blinken_5fach](https://github.com/Kruemelbahn/lightControl/tree/main/Software/Blinken_5fach) läßt alle Ausgänge blinken
  - [Einsatzfahrzeuge](https://github.com/Kruemelbahn/lightControl/tree/main/Software/Einsatzfahrzeuge) generiert zwei verschiedene Blinkfolgen für Einsatzfahrzeuge
- auf ATtiny13-Basis:
  - [Belebtes_Haus_mit_TV_Attiny](https://github.com/Kruemelbahn/lightControl/tree/main/Software/Belebtes_Haus_mit_TV_Attiny) simuliert ein belebtes Haus, es werden einige LEDs zufällig eine- und ausgeschaltet (Zimmerbeleuchtung), ein weiterer Ausgang simuliert einen flimmernden Fernsehgerät.
  - [Blinken](https://github.com/Kruemelbahn/lightControl/tree/main/Software/Blinken) läßt den Ausgang PB0 blinken
  - [Blitz_Blinker](https://github.com/Kruemelbahn/lightControl/tree/main/Software/Blitz_Blinker) ist die Implementierung des [FotoMichel](https://github.com/Kruemelbahn/FotoMichel) auf AVR-Basis anstelle eines PIC.
    Die Hardware ist gegenüber dem originalen FotoMichel einfacher gehalten und hat nur einen Triggereingang für die Blitzlichter.
  - [LaufLicht_ATiny13](https://github.com/Kruemelbahn/LightControl/tree/main/Software/LaufLicht_ATiny13) ist die Implementierung eines Lauflichts über die Ausgänge PB0...PB4

Der Quellcode wird nur benötigt, wenn
- man neugierig ist
- oder den Quellcode ändern und somit neu kompilieren möchte.
Zum Kompilieren wird ein AVR-Compiler (z.B. das ATMEL-Studio bzw. die Arduino-IDE) benötigt.

Ansonsten reichen die Hex-Dateien völlig aus, diese werden in den ATtiny13 geflasht.
Die Software auf dem ATtiny13 läuft mit den Default-Fuses: low=0x6A high=0xFF

![Lichtcomputer mit PIC](/Images/Lichtcomputer(PIC).png)
![Lichtcomputer mit ATTiny](/Images/Lichtcomputer(ATMEL).png)

﻿# LightControl

...ist eine kleine Sammlung von Lichtsteuerungen (mit analoger Ansteuerung) auf meiner Modellbahn:

Unterlagen zur universell einsetzbare Hardware mit der zugehörigen Dokumentation ist nur auf Anfrage erhältlich.

Nachfolgende Softwarepakete stehen unter [Software](https://github.com/Kruemelbahn/lightControl/tree/main/Software) zur Verfügung

- [Belebtes_Haus_mit_TV_Attiny](https://github.com/Kruemelbahn/lightControl/tree/main/Software/Belebtes_Haus_mit_TV_Attiny) simuliert ein belebtes Haus, es werden einige LEDs zufällig eine- und ausgeschaltet (Zimmerbeleuchtung), ein weiterer Ausgang simuliert einen flimmernden Fernsehgerät.
- [Blinken](https://github.com/Kruemelbahn/lightControl/tree/main/Software/Blinken) läßt den Ausgang PB0 blinken
- [Blitz_Blinker](https://github.com/Kruemelbahn/lightControl/tree/main/Software/Blitz_Blinker) ist die Implementierung des [FotoMichel](https://github.com/Kruemelbahn/FotoMichel) auf AVR-Basis anstelle eines PIC.
  Die Hardware ist gegenüber dem originalen FotoMichel einfacher gehalten und hat nur einen Triggereingang für die Blitzlichter.
- [Lauflicht](https://github.com/Kruemelbahn/lightControl/tree/main/Software/Lauflicht) ist die Implementierung eines Lauflichts über die Ausgänge PB0...PB4

# Arduino Cathode Clock

_Version 0.1.0_

First setup to have the Arduino Nano control the 74HC595 shift registers light-up the right LEDs in the 7-segment LED displays depending on the time controlled by the RTC module. This code needs a lot of refactoring still.

## Required Parts
* 4x 74HC595 shift registers
* 4x 7-segment cathode displays (large ones (4,5cm/1.8inch))
* Arduino Uno/Arduino Nano
* 28x resistors 200 ohm (depending on initial brightness of LEDs)
* Real Time Clock (RTC) module
* On/Off switch/button
* Push button (for controls)
* Potentiometer (for minutes/hour-settings)
* 9V adapter including connection contact
* Lots of wire

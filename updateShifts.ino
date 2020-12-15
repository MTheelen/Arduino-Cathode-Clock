
/*Expanded for use in clock*/
void updateShiftRegister(int number, )
{
  switch (number) {
  case 0:
    bitSet(leds, 0);
    bitSet(leds, 1);
    bitSet(leds, 2);
    bitSet(leds, 3);
    bitSet(leds, 5);
    bitSet(leds, 7);
    break;
  case 1:
    bitSet(leds, 1);
    bitSet(leds, 2);
    break;
  case 2:
    bitSet(leds, 0);
    bitSet(leds, 2);
    bitSet(leds, 3);
    bitSet(leds, 6);
    bitSet(leds, 7);
    break;
  case 3:
    bitSet(leds, 1);
    bitSet(leds, 2);
    bitSet(leds, 3);
    bitSet(leds, 6);
    bitSet(leds, 7);
    break;
  case 4:
    bitSet(leds, 1);
    bitSet(leds, 2);
    bitSet(leds, 6);
    bitSet(leds, 5);
    break;
  case 5:
    bitSet(leds, 1);
    bitSet(leds, 3);
    bitSet(leds, 5);
    bitSet(leds, 6);
    bitSet(leds, 7);
    break;
  case 6:
    bitSet(leds, 0);
    bitSet(leds, 1);
    bitSet(leds, 3);
    bitSet(leds, 5);
    bitSet(leds, 6);
    bitSet(leds, 7);
    break;
  case 7:
    bitSet(leds, 1);
    bitSet(leds, 2);
    bitSet(leds, 3);
    break;
  case 8:
    bitSet(leds, 0);
    bitSet(leds, 1);
    bitSet(leds, 2);
    bitSet(leds, 3);
    bitSet(leds, 5);
    bitSet(leds, 6);
    bitSet(leds, 7);
    break;
  case 9:
    bitSet(leds, 1);
    bitSet(leds, 2);
    bitSet(leds, 3);
    bitSet(leds, 5);
    bitSet(leds, 6);
    bitSet(leds, 7);
    break;
  default:
    bitSet(leds, 0);
    bitSet(leds, 3);
    bitSet(leds, 5);
    bitSet(leds, 6);
    bitSet(leds, 7);
    break;
  }







  
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

#include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68

//Clockhand pins (output)
int latchPinMinuteHandSingles = 0;
int clockPinMinuteHandSingles = 1;
int dataPinMinuteHandSingles = 2;

int latchPinMinuteHandDoubles = 3;
int clockPinMinuteHandDoubles = 4;
int dataPinMinuteHandDoubles = 5;

int latchPinHourHandSingles = 6;
int clockPinHourHandSingles = 7;
int dataPinHourHandSingles = 8;

int latchPinHourHandDoubles = 9;
int clockPinHourHandDoubles = 10;
int dataPinHourHandDoubles = 11;

//input pins
int sensorPinMinuteHand = A5;    // select the input pin for the potentiometer meant for selecting minutes
int sensorPinHourHand = A6;    // select the input pin for the potentiometer meant for selecting hours

//Memory variables
byte ledsMinuteHandSingles = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off
byte ledsMinuteHandDoubles = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off
byte ledsHourHandSingles = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off
byte ledsHourHandDoubles = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off
int sensorMinuteHandValue = 0;  // variable to store the value coming directly from the potentiometer for minutes
int sensorMinuteHandMemory = 0; // variable for tracking any changes to the potentiometer for minutes
int sensorHourHandValue = 0;  // variable to store the value coming directly from the potentiometer for hours
int sensorHourHandMemory = 0; // variable for tracking any changes to the potentiometer for hours

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup() 
{
  // Set all the pins of 74HC595 as OUTPUT for all 4 segment LEDs
  pinMode(latchPinMinuteHandSingles, OUTPUT); 
  pinMode(clockPinMinuteHandSingles, OUTPUT);
  pinMode(dataPinMinuteHandSingles, OUTPUT); 
  
  pinMode(latchPinMinuteHandDoubles, OUTPUT); 
  pinMode(clockPinMinuteHandDoubles, OUTPUT);
  pinMode(dataPinMinuteHandDoubles, OUTPUT); 
  
  pinMode(latchPinHourHandSingles, OUTPUT);
  pinMode(clockPinHourHandSingles, OUTPUT);
  pinMode(dataPinHourHandSingles, OUTPUT);
  
  pinMode(latchPinHourHandDoubles, OUTPUT);  
  pinMode(clockPinHourHandDoubles, OUTPUT);
  pinMode(dataPinHourHandDoubles, OUTPUT);

  //Reset on init
  resetNumber();//TODO: reset all 4 segment LEDs
  
  //Select baudrate for debugging
  Serial.begin(9600); // open the serial port at 9600 bps:
}

/*
 * loop() - this function runs over and over again
 */
void loop() 
{
  

  int sensorValue = returnNewValue(analogRead(sensorPin));
  Serial.println(sensorValue);
  updateShiftRegister(sensorValue);

 
}



/*Detect change on potentiometer*/
int returnNewValue(int detectedValue){
   detectedValue = map(detectedValue, 0, 1024, 0, 10);
   if(detectedValue != sensorValueMemory){
    sensorValueMemory = detectedValue;
    resetNumber();
    return detectedValue;
   }
   else return sensorValueMemory;
}

/*reset numbers*/
void resetNumber(){  
  updateShiftRegister(0);
  leds=0;
}


/*
 * updateShiftRegister() - This function sets the latchPin to low, then calls the Arduino function 'shiftOut' to shift out contents of variable 'leds' in the shift register before putting the 'latchPin' high again.

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
 */  

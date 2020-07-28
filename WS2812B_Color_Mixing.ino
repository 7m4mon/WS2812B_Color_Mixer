/*
Color addressable LEDs control using Adafruit NeoPixel library
With WAVGAT328

 Parts required:
 1m strip of addressable LEDs http://store.arduino.cc/products/C000083
 
 This example code is part of the public domain
 */

#include <Adafruit_NeoPixel.h>

const int NUMPIXELS = 256; //number of LEDs in matrix (8x32 or 16x16)
const int LEDsPin = 9;    // LEDs connected to digital pin 9

const int redPotPin = A0;      // pin to control red
const int greenPotPin = A1;   // pin to control green
const int bluePotPin = A2;   // pin to control blue

const int lockSwPin = 10;     // pin to Lock/Free Switch

int redValue = 0; // value to write to the red LED
int greenValue = 0; // value to write to the green LED
int blueValue = 0; // value to write to the blue LED

int redPotValue = 0; // variable to hold the value from the red pot
int greenPotValue = 0; // variable to hold the value from the green pot
int bluePotValue = 0; // variable to hold the value from the blue pot

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDsPin, NEO_GRB + NEO_KHZ400); // NEO_KHZ800 → NEO_KHZ400

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  // set the digital pin as output
  pinMode(LEDsPin, OUTPUT);
  pinMode(lockSwPin, INPUT_PULLUP);
  pixels.begin();
}

void loop() {
  if(!digitalRead(lockSwPin)){
      digitalWrite(13,HIGH);
      // Read the pots first:
    
      // read the value from the red pot control:
      redPotValue = analogRead(redPotPin);
      // give the ADC a moment to settle
      delay(5);
      // read the value from the green pot control:
      greenPotValue = analogRead(greenPotPin);
      // give the ADC a moment to settle
      delay(5);
      // read the value from the blue pot control:
      bluePotValue = analogRead(bluePotPin);
    
      // print out the values to the serial monitor
      Serial.print("Rp: ");
      Serial.print(redPotValue);
      Serial.print("\t Gp: ");
      Serial.print(greenPotValue);
      Serial.print("\t Bp: ");
      Serial.println(bluePotValue);
    
      /*
      In order to use the values from the pots for the LEDs,
      you need to do some math. 
      The ADC of WAVGAT provides a 12-bit number,(but Max is 4064 w/ my potmeter)
      but analogWrite() uses 8 bits. You'll want to divide your
      sensor readings by 4 to keep them in range of the output.
      */
      redValue = map(redPotValue, 0, 4064, 255, 0);
      greenValue = map(greenPotValue, 0, 4064, 255, 0);
      blueValue = map(bluePotValue, 0, 4064, 255, 0);
    
      //  print out the mapped values
      Serial.print("Rm: ");
      Serial.print(redValue);
      Serial.print("\t Gm: ");
      Serial.print(greenValue);
      Serial.print("\t Bm: ");
      Serial.println(blueValue);
      // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
      for (int i = 0; i < NUMPIXELS; i++) {
           // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
           pixels.setPixelColor(i, pixels.Color(redValue, greenValue, blueValue));
      }
      pixels.show();
      digitalWrite(13,LOW);
  }
  delay(50); // Delay for a period of time (in milliseconds).
}

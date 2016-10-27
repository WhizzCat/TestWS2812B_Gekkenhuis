#include <Arduino.h>

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 9

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 5

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
	Serial.begin(57600);
	Serial.println("resetting");
	LEDS.addLeds<WS2812B,DATA_PIN,GRB>(leds,NUM_LEDS);
	LEDS.setBrightness(255);
}

void loop() 
{ 
  // Floor, side of window (side of building)

  // Bottom right (Front)
  leds[4] = CRGB::Purple;
  // Bottom left (Front)
  leds[0] = CRGB::Purple;

  // Middle left (Front)
  leds[5] = CRGB::Red;
  // Middle right (Front)
  leds[1] = CRGB::Blue;

  // Top middle (Front)
  leds[8] = CRGB::White;
  
  // Top middle (Right)
  leds[3] = CRGB::Yellow;
  // Bottom middle (Right)
  leds[2] = CRGB::Blue;

  // Roof right (hidden)
  leds[6] = CRGB::Orange;
  // Roof left (hidden)
  leds[7] = CRGB::Orange;

  
  
  FastLED.show();
  /*
	for(int i=0;i<NUM_LEDS;i++)
	{
		leds[i] = CRGB(255, 0, 0);
    delay(500);
    FastLED.show();
		leds[i] = CRGB(0, 0, 0);
		// Show the leds
		FastLED.show();
		delay(500);
	}
 */
}

void randomLights()
{
  randomSeed(analogRead(A0));

  int color1 = random(0,255);
  int color2 = random(0,255);
  int color3 = random(0,255);
  
  int wait = random(10, 150);
  int led = random (0,9);
  int cycles = random(2, 5);

  for(int i=0;i<cycles;i++)
  {
    leds[led] = CRGB(color1,color2,color3);
  
    FastLED.show();
  
    delay(random(10, 150));

    leds[led] = CRGB(0,0,0);
    
    FastLED.show();
  
    delay(random(10, 150));
  }
}


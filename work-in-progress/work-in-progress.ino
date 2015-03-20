#include <JigglyLights.h>
#include <FastLED.h>

#define PIN 6

/**
 * Set this variable to the amount of LEDs
 * you have on your single strip.
 */
#define NUM_LEDS 40

/**
 * If you rather have a LED matrix built as
 * one strip with "edges", specify the X and
 * Y dimensions of that matrix.
 */
#define LEDS_X 8
#define LEDS_Y 5

CRGB leds[NUM_LEDS];

JigglyLights jiggly;


void setup() {
  Serial.begin(57600);
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}


void loop() {
  int doIt;
  
  if(Serial.available() > 0) {
  
    doIt = Serial.read();
    Serial.println(doIt, DEC);
    
    if(doIt == 49) {
      jiggly.matrixWave(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 2), 500);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 50) {
      jiggly.matrixWaveInverted(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 2), 500);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 51) {
      jiggly.matrixWaveOne(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 2), 500);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 52) {
      jiggly.matrixWaveOneRandom(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 2), 500);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 53) {
      jiggly.matrixProgressbar(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 2), 1000);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 54) {
      jiggly.matrixProgressbarCentered(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 2), 1000);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 55) {
      jiggly.matrixLevel(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 2), 500);
      jiggly.clearAll(leds, NUM_LEDS);
    }
  }
}

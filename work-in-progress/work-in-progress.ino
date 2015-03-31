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
  CRGB stripeColors[2] = { CRGB(20, 0, 0), CRGB(0, 0, 20) };
  
  if(Serial.available() > 0) {
  
    doIt = Serial.read();
    Serial.println(doIt, DEC);
    
    if(doIt == 49) {
      Serial.println((2 - 5), DEC);
      jiggly.matrixWave(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 20), 500);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 50) {
      jiggly.matrixWaveInverted(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 20), 500);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 51) {
      jiggly.matrixWaveOne(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 20), 500);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 52) {
      jiggly.matrixWaveOneRandom(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 20), 500);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 53) {
      jiggly.matrixProgressbar(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 20), 1000);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 54) {
      jiggly.matrixProgressbarCentered(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 20), 1000);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 55) {
      jiggly.matrixLevel(leds, LEDS_X, LEDS_Y, CRGB(0, 0, 20), 500);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 56) {
      jiggly.transition(leds, NUM_LEDS, CRGB(30, 0, 0), CRGB(0, 30, 0), 4000);
      jiggly.transition(leds, NUM_LEDS, CRGB(0, 30, 0), CRGB(0, 0, 30), 4000);
      jiggly.transition(leds, NUM_LEDS, CRGB(0, 0, 30), CRGB(30, 0, 0), 4000);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 57) {
      jiggly.matrixStripes(leds, LEDS_X, LEDS_Y, stripeColors, 2, 1000);
      jiggly.clearAll(leds, NUM_LEDS);
    }
    else if(doIt == 48) {
      jiggly.matrixStripesDiag(leds, LEDS_X, LEDS_Y, stripeColors, 2, 1000);
      jiggly.clearAll(leds, NUM_LEDS);
    }
  }
}

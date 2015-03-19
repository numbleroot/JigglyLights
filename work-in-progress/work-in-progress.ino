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
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}


void loop() {
  jiggly.matrixWave(leds, LEDS_X, LEDS_Y, CRGB(10, 0, 0), 800);
}
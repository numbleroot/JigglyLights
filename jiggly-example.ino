#include <FastLED.h>
#include <JigglyLights.h>

/* The GPIO PIN you've attached the LED strip to. */
#define PIN 6

/* Number of LEDs of your strip. */
#define NUM_LEDS 31

/* LED array to individually address LEDs. */
CRGB leds[NUM_LEDS];
/* Jiggly instance to call the functions from. */
JigglyLights jiggly;


void setup() {
  /* See FastLED repo for details. */
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {

  /* Call JigglyLights animations through an instance like this. */
  jiggly.runner(leds, NUM_LEDS, CRGB::Red, 1000);

  /* See JigglyLights.h for animation documentation. */
}
#include <FastLED.h>

#define PIN 6
#define NUM_LEDS 31

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {
  runAllAnimations(leds, NUM_LEDS, 40, 2000);
}
#include <JigglyLights.h>
#include <FastLED.h>

#define PIN 6
#define NUM_LEDS 31

CRGB leds[NUM_LEDS];
JigglyLights jiggly;


void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {
  jiggly.runAllAnimations(leds, NUM_LEDS, 40, 2000);
}

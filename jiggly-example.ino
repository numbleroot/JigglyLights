#include <FastLED.h>
#include <JigglyLights.h>

//the GPIO PIN you've attached the LED strip to
#define PIN 6

//Number of LEDs of your strip
#define NUM_LEDS 31

//LED array to individually address LEDs
CRGB leds[NUM_LEDS];
//jiggly instance to call the functions from
JigglyLights jiggly;


void setup() {
  //see FastLED repo for details
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {

  //call JigglyLights animations through an instance like this
  jiggly.runner(leds, NUM_LEDS, CRGB::Red, 1000);

  //see JigglyLights.h for animation documentation
}
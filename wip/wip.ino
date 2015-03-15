#include <FastLED.h>


#define PIN 6
#define NUM_LEDS 31

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {
  //progressbar(leds, NUM_LEDS, 0, 20, 0, 10000);
  progressbarCentered(leds, NUM_LEDS, 0, 0, 20, 2000);
}

void runner(CRGB *leds, int numOfLeds, int red, int green, int blue, int duration) {

  int i, wait;

  wait = duration / (numOfLeds * 2);

  for (i = 0; i < numOfLeds; i++) {

    leds[i].setRGB(red, green, blue);
    FastLED.show();
    delay(wait);
    leds[i].setRGB(0, 0, 0);
    FastLED.show();
  }

  for (i = (numOfLeds - 1); i > 0; i--) {

    leds[i].setRGB(red, green, blue);
    FastLED.show();
    delay(wait);
    leds[i].setRGB(0, 0, 0);
    FastLED.show();
  }
}

void progressbar(CRGB *leds, int numOfLeds, int red, int green, int blue, int duration) {

  int i, wait;

  wait = duration / (numOfLeds * 4);

  for (i = 0; i < numOfLeds; i++) {

    leds[i].setRGB(red, green, blue);
    FastLED.show();
    delay(wait);
  }

  for (i = 0; i < numOfLeds; i++) {

    leds[i].setRGB(0, 0, 0);
    FastLED.show();
    delay(wait);
  }

  for (i = numOfLeds; i >= 0; i--) {

    leds[i].setRGB(red, green, blue);
    FastLED.show();
    delay(wait);
  }

  for (i = numOfLeds; i >= 0; i--) {

    leds[i].setRGB(0, 0, 0);
    FastLED.show();
    delay(wait);
  }
}

void progressbarCentered(CRGB *leds, int numOfLeds, int red, int green, int blue, int duration) {

  int i, center, inv, wait;

  center = numOfLeds / 2;
  wait = duration / (numOfLeds * 2);

  for (i = center; i < numOfLeds; i++) {

    inv = (numOfLeds - i) - 1;
    leds[i].setRGB(red, green, blue);
    leds[inv].setRGB(red, green, blue);
    FastLED.show();
    delay(wait);
  }

  for (i = (numOfLeds - 1); i >= center; i--) {

    inv = (numOfLeds - i) - 1;
    leds[i].setRGB(0, 0, 0);
    leds[inv].setRGB(0, 0, 0);
    FastLED.show();
    delay(wait);
  }
}

void blinking(CRGB *leds, int numOfLeds, int red, int green, int blue, int duration) {

  int i, wait;
  
  wait = duration / 2;

  for (i = 0; i < numOfLeds; i++) {

    leds[i].setRGB(red, green, blue);
  }

  FastLED.show();
  delay(wait);

  for (i = 0; i < numOfLeds; i++) {

    leds[i].setRGB(0, 0, 0);
  }

  FastLED.show();
  delay(wait);
}

void blinkingParts(CRGB *leds, int numOfLeds, int parts, int red, int green, int blue, int duration) {

  int i, steps, wait;

  steps = numOfLeds / parts;
  wait = duration / 2;

  for (i = 0; i < numOfLeds; i += steps) {

    leds[i].setRGB(red, green, blue);
  }

  FastLED.show();
  delay(wait);

  for (i = 0; i < numOfLeds; i += steps) {

    leds[i].setRGB(0, 0, 0);
  }

  FastLED.show();
  delay(wait);
}

//ms = time of pulse
void pulse(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms) {
  int numOfSteps = 20;

  for (int step = 0; step < numOfSteps; step++) {

    int tempRed = red - (step * (red / numOfSteps));
    int tempGreen = green - (step * (green / numOfSteps));
    int tempBlue = blue - (step * (blue / numOfSteps));

    for (int i = 0; i < numOfLeds; i++) {
      leds[i].setRGB(tempRed, tempGreen, tempBlue);
    }

    FastLED.show();
    delay(ms / numOfSteps);
  }
}

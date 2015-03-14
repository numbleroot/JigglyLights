#include <FastLED.h>


#define PIN 6
#define NUM_LEDS 31

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {
  progressbarCentered(leds, NUM_LEDS, 0, 20, 0, 100);
}

void runner(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms) {

    int i;

    for(i = 0; i < numOfLeds; i++) {

        leds[i].setRGB(red, green, blue);
        FastLED.show();
        delay(ms);
        leds[i].setRGB(0, 0, 0);
        FastLED.show();
    }

    for(i = (numOfLeds - 1); i > 0; i--) {

        leds[i].setRGB(red, green, blue);
        FastLED.show();
        delay(ms);
        leds[i].setRGB(0, 0, 0);
        FastLED.show();
    }
}

void progressbar(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms) {

    int i;

    for(i = 0; i < numOfLeds; i++) {

      leds[i].setRGB(red, green, blue);
      FastLED.show();
      delay(ms);
    }

    for(i = 0; i < numOfLeds; i++) {

      leds[i].setRGB(0, 0, 0);
      FastLED.show();
      delay(ms);
    }

    for(i = numOfLeds; i >= 0; i--) {

      leds[i].setRGB(red, green, blue);
      FastLED.show();
      delay(ms);
    }

    for(i = numOfLeds; i >= 0; i--) {

      leds[i].setRGB(0, 0, 0);
      FastLED.show();
      delay(ms);
    }
}

void progressbarCentered(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms) {

    int i, center, inv;

    center = numOfLeds / 2;
    
    for(i = center; i < numOfLeds; i++) {
    
        inv = (numOfLeds - i) - 1;
        leds[i].setRGB(red, green, blue);
        leds[inv].setRGB(red, green, blue);
        FastLED.show();
        delay(ms);
    }
    
    for(i = (numOfLeds - 1); i >= center; i--) {
    
        inv = (numOfLeds - i) - 1;
        leds[i].setRGB(0, 0, 0);
        leds[inv].setRGB(0, 0, 0);
        FastLED.show();
        delay(ms);
    }
}

void blinking(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms) {

  int i;

  for(i = 0; i < numOfLeds; i++) {

    leds[i].setRGB(red, green, blue);
  }

  FastLED.show();
  delay(ms);

  for(i = 0; i < numOfLeds; i++) {

    leds[i].setRGB(0, 0, 0);
  }

  FastLED.show();
  delay(ms);
}

void blinkingParts(CRGB *leds, int numOfLeds, int parts, int red, int green, int blue, int ms) {

    int i, steps;

    steps = numOfLeds / parts;

    for(i = 0; i < numOfLeds; i += steps) {

        leds[i].setRGB(red, green, blue);
    }

    FastLED.show();
    delay(ms);

    for(i = 0; i < numOfLeds; i += steps) {

        leds[i].setRGB(0, 0, 0);
    }

    FastLED.show();
    delay(ms);
}

//ms = time of pulse
void pulse(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms){
  int numOfSteps = 20;

  for (int step = 0; step < numOfSteps; step++){

    int tempRed = red - (step * (red / numOfSteps));
    int tempGreen = green - (step * (green / numOfSteps));
    int tempBlue = blue - (step * (blue / numOfSteps));

    for (int i = 0; i < numOfLeds; i++){
      leds[i].setRGB(tempRed, tempGreen, tempBlue); 
    }
    
    FastLED.show();
    delay(ms/numOfSteps);
  }
}

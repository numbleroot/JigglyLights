#include <FastLED.h>


#define PIN 6
#define NUM_LEDS 31

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {
  blinking(leds, NUM_LEDS, 0, 10, 0, 5000);
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

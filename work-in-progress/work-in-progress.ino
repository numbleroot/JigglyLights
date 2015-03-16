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
//  chimes();
}


void chimes(){
  jiggly.runner(leds, NUM_LEDS, CRGB(70,0,100), 6600);
  jiggly.runner(leds, NUM_LEDS, CRGB(100,60,10), 6600);
//  jiggly.runner(leds, NUM_LEDS, CRGB(0,100,30), 6600);
  
  jiggly.flashyShit(leds, NUM_LEDS, 50, 6600);
  jiggly.flashyShit(leds, NUM_LEDS, 50, 6600);
  
  jiggly.progressbarCentered(leds, NUM_LEDS, CRGB(30,0,100), 3300);
  delay(390);
  for (int i = 0; i < 3; i++){
    jiggly.blinking(leds,NUM_LEDS,CRGB(0,60,100), 200);
  }
  jiggly.blinking(leds,NUM_LEDS,CRGB(0,60,100), 300);
  jiggly.blinking(leds,NUM_LEDS,CRGB(0,60,100), 210);
  
  
  jiggly.progressbarCentered(leds, NUM_LEDS, CRGB(100,0,0), 3300);
  delay(395);
  for (int i = 0; i < 3; i++){
    jiggly.blinking(leds,NUM_LEDS,CRGB(100,20,20), 200);
  }
  jiggly.blinking(leds,NUM_LEDS,CRGB(100,20,20), 300);
  jiggly.blinking(leds,NUM_LEDS,CRGB(100,20,20), 210);
  
  jiggly.progressbarCentered(leds, NUM_LEDS, CRGB(0,100,30), 3300);
  delay(395);
  for (int i = 0; i < 3; i++){
    jiggly.blinking(leds,NUM_LEDS,CRGB(0,100,40), 200);
  }
  jiggly.blinking(leds,NUM_LEDS,CRGB(0,100,40), 300);
  jiggly.blinking(leds,NUM_LEDS,CRGB(0,100,40), 210);
  delay(10000);
}

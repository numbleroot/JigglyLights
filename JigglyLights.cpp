#include "Arduino.h"
#include "JigglyLights.h"
#include "FastLED.h"


JigglyLights::JigglyLights() {}

void JigglyLights::runner(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms) {

    int i;

    for(i = 0; i < numOfLeds; i++) {

        leds[i].setRGB(red, green, blue);
        FastLED.show();
        delay(ms);
        leds[i].setRGB(0, 0, 0);
        FastLED.show();
    }
}
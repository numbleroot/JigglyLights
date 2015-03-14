#ifndef JigglyLights_h
#define JigglyLights_h

#include "Arduino.h"
#include "FastLED.h"

class JigglyLights {

    public:
        JigglyLights();
        void runner(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms);
};

#endif
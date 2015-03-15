#ifndef JigglyLights_h
#define JigglyLights_h

#include "Arduino.h"
#include "FastLED.h"

class JigglyLights {

    public:

        /**
         * Constructor
         */
        JigglyLights();


        /**
         * randomColor
         * Returns a CRGB color based on the maximum
         * intensity value supplied.
         */
        CRGB randomColor(int maxIntensity);


        /**
         * randomPrettyColor
         * Returns a CRGB color randomly chosen out of
         * the prettyColors array. An array built from completely
         * subjective selected colors predefined by the FastLED library.
         */
        CRGB randomPrettyColor();


        /**
         * clearAll
         * Sets all LEDs to black (= nothing).
         */
        void clearAll(CRGB *leds, int numOfLeds);


        /**
         * runner
         * Let one light run across the whole LED strip and come back. Shiny.
         */
        void runner(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * colorRunner
         * Same as runner but with a new random color for each next step.
         */
        void colorRunner(CRGB *leds, int numOfLeds, int intensity, int duration);


        /**
         * progressbar
         * Fill the LED strip one light at a time. After reaching the other end
         * defined via the numOfLeds variable it will clean up after itself.
         */
        void progressbar(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * progressbarCentered
         * A progress bar started from the calculated center of the LED strip.
         * Grows in both directions and comes back again.
         */
        void progressbarCentered(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * blinking
         * Flash all LEDs of the strip for duration ms long and turn them black
         * afterwards for duration ms long.
         */
        void blinking(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * blinkingParts
         * Same as blinking but only light each parts LED of the strip. If you
         * supply 5 as parts, every fifth light will be turned on in color.
         */
        void blinkingParts(CRGB *leds, int numOfLeds, int parts, CRGB color, int duration);


        /**
         * pulse
         * WIP: Will make the LEDs glow in color for duration ms long.
         */
        void pulse(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * sparkleAt
         * Spread some nice sparkling at supplied index.
         */
        void sparkleAt(int index, CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * sparkleAtRandomIndex
         * Same as sparkleAt but with an randomly chosen starting point.
         */
        void sparkleAtRandomIndex(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * flashyShit
         * Start from the center and spread one light which is a random color
         * in each step to both sides of the strip.
         */
        void flashyShit(CRGB *leds, int numOfLeds, int maxIntensity, int duration);


        /**
         * randomIndexFill
         * Randomly fill the next LED until all LEDs are shining.
         */
        void randomIndexFill(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * transition
         * WIP: Smoothely go from one color of all LEDs to another.
         */
        void transition(CRGB *leds, int numOfLeds, CRGB firstColor, CRGB secondColor, int duration);


        /**
         * runAllAnimations
         * Collection of all effects above.
         */
        void runAllAnimations(CRGB *leds, int numOfLeds, int maxIntensity, int durationEach);
};

#endif
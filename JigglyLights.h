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
         * highest
         * Throw in an array of values (e.g. RGB values) and the amount
         * of values and you will get returned the highest of all values
         * (based on absolute values).
         */
        int highest(int *vals, int numOfVals);


        /**
         * calcMatrixIndex
         * Calculate the index of one light on a continous soldered
         * LED matrix.
         */
        int calcMatrixIndex(int x, int y, int leds_x);


        /**
         * clearAll
         * Sets all LEDs to black (= nothing).
         */
        void clearAll(CRGB *leds, int numOfLeds);


        /**
         * runner
         * Let one light run across the whole LED strip and come back. Shiny.
         * If color parameter is black(0-0-0), random colors will be displayed.
         */
        void runner(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * progressbar
         * Fill the LED strip one light at a time. After reaching the other end
         * defined via the numOfLeds variable it will clean up after itself.
         * If color parameter is black(0-0-0), random colors will be displayed.
         */
        void progressbar(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * progressbarCentered
         * A progress bar started from the calculated center of the LED strip.
         * Grows in both directions and comes back again.
         * If color parameter is black(0-0-0), random colors will be displayed.
         */
        void progressbarCentered(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * blinking
         * Flash all LEDs of the strip for duration ms long and turn them black
         * afterwards for duration ms long.
         * If color parameter is black(0-0-0), random colors will be displayed.
         */
        void blinking(CRGB *leds, int numOfLeds, CRGB color, int duration);


        /**
         * blinkingParts
         * Same as blinking but only light each parts LED of the strip. If you
         * supply 5 as parts, every fifth light will be turned on in color.
         * If color parameter is black(0-0-0), random colors will be displayed.
         */
        void blinkingParts(CRGB *leds, int numOfLeds, int parts, CRGB color, int duration);


        /**
         * glow
         * Let your LEDs glow steadily in the given duration intervall.
         * Somewhat like a notification pulse.
         */
        void glow(CRGB *leds, int numOfLeds, CRGB color, int duration);


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
         * gradientLoop
         * Loop through color gradient with specified maximum brightness.
         */
        void gradientLoop(CRGB *leds, int numOfLeds, int brightness, int duration);


        /**
         * runAllAnimations
         * Collection of all effects above.
         */
        void runAllAnimations(CRGB *leds, int numOfLeds, int maxIntensity, int durationEach);


        /**
         * chimes
         * Have some beautiful effects to the first ca. 55 seconds of "Chimes".
         */
        void chimes(CRGB *leds, int numOfLeds);


        /**
         * matrixWave
         * Take this LED thing two-dimensional! Run a wave across the strip.
         * Provide the dimensions of your matrix and see how the wave builds up.
         */
        void matrixWave(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration);


        /**
         * matrixWaveInverted
         * Same as matrixWave but in the other direction.
         */
        void matrixWaveInverted(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration);


        /**
         * matrixWaveOne
         * Run one bar over the LED matrix.
         */
        void matrixWaveOne(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration);


        /**
         * matrixWaveOneRandom
         * For each coloumn of your LED matrix choose a random amount between 1 and leds_y
         * of LEDs to light up on that coloumn. Other than that, same as matrixWaveOne.
         */
        void matrixWaveOneRandom(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration);


        /**
         * matrixProgressbar
         * Same as progressbar but for a matrix.
         */
        void matrixProgressbar(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration);


        /**
         * matrixProgressbarCentered
         * Same as progressbarCentered but for a matrix.
         */
        void matrixProgressbarCentered(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration);


        /**
         * matrixLevel
         * Let a bar rise up and down on your matrix.
         */
        void matrixLevel(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration);


        /**
         * matrixStripes
         * Light up each row with all colors provided by color alternately. Specify how many
         * colors you are using via numOfColors.
         */
        void matrixStripes(CRGB *leds, int leds_x, int leds_y, CRGB *colors, int numOfColors, int duration);


        /**
         * matrixStripesDiag
         * Same as matrixStripes but "rotated" by 45 degrees.
         */
        void matrixStripesDiag(CRGB *leds, int leds_x, int leds_y, CRGB *colors, int numOfColors, int duration);
};

#endif
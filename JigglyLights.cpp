#include "Arduino.h"
#include "JigglyLights.h"
#include "FastLED.h"


/* To be expanded! */
CRGB prettyColors[] = {
  CRGB::Red,
  CRGB::Salmon,
  CRGB::SeaGreen,
  CRGB::YellowGreen
};


JigglyLights::JigglyLights() {}


CRGB JigglyLights::randomColor(int maxIntensity) {

  int randRed, randGreen, randBlue;

  if(maxIntensity <= 255) {
    randRed = random8(maxIntensity);
    randGreen = random8(maxIntensity);
    randBlue = random8(maxIntensity);

    return CRGB(randRed, randGreen, randBlue);
  } else {
    /* u stupid. */
    return CRGB::Black;
  }
}


CRGB JigglyLights::randomPrettyColor() {

  int randomIndex;

  randomIndex = random8(sizeof(prettyColors) / sizeof(prettyColors[0]));

  return prettyColors[randomIndex];
}


void JigglyLights::clearAll(CRGB *leds, int numOfLeds) {

  int i;

  for(i = 0; i < numOfLeds; i++) {
    leds[i] = CRGB::Black;
  }

  FastLED.show();
}


void JigglyLights::runner(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int i, wait;

  wait = duration / (numOfLeds * 2);

  for(i = 0; i < numOfLeds; i++) {

    leds[i] = color;
    FastLED.show();
    delay(wait);

    leds[i] = CRGB::Black;
    FastLED.show();
  }

  for(i = (numOfLeds - 1); i > 0; i--) {

    leds[i] = color;
    FastLED.show();
    delay(wait);

    leds[i] = CRGB::Black;
    FastLED.show();
  }
}


void JigglyLights::colorRunner(CRGB *leds, int numOfLeds, int intensity, int duration) {

  int i, wait;

  wait = duration / (numOfLeds * 2);

  if(intensity < 0) {
    intensity = 0;
  }

  if(intensity > 255) {
    intensity = 255;
  }

  for(i = 0; i < numOfLeds; i++) {

    leds[i] = randomColor(intensity);
    FastLED.show();
    delay(wait);

    leds[i] = CRGB::Black;
    FastLED.show();
  }

  for(i = (numOfLeds - 1); i > 0; i--) {

    leds[i] = randomColor(intensity);
    FastLED.show();
    delay(wait);

    leds[i] = CRGB::Black;
    FastLED.show();
  }
}


void JigglyLights::progressbar(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int i, wait;

  wait = duration / (numOfLeds * 4);

  for (i = 0; i < numOfLeds; i++) {

    leds[i] = color;
    FastLED.show();
    delay(wait);
  }

  for (i = 0; i < numOfLeds; i++) {

    leds[i] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }

  for (i = numOfLeds; i >= 0; i--) {

    leds[i] = color;
    FastLED.show();
    delay(wait);
  }

  for (i = numOfLeds; i >= 0; i--) {

    leds[i] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }
}


void JigglyLights::progressbarCentered(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int i, center, inv, wait;

  center = numOfLeds / 2;
  wait = duration / (numOfLeds * 2);

  for (i = center; i < numOfLeds; i++) {

    inv = (numOfLeds - i) - 1;
    leds[i] = color;
    leds[inv] = color;
    FastLED.show();
    delay(wait);
  }

  for (i = (numOfLeds - 1); i >= center; i--) {

    inv = (numOfLeds - i) - 1;
    leds[i] = CRGB::Black;
    leds[inv] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }
}


void JigglyLights::blinking(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int i, wait;

  wait = duration / 2;

  for (i = 0; i < numOfLeds; i++) {

    leds[i] = color;
  }

  FastLED.show();
  delay(wait);

  for (i = 0; i < numOfLeds; i++) {

    leds[i] = CRGB::Black;
  }

  FastLED.show();
  delay(wait);
}


void JigglyLights::blinkingParts(CRGB *leds, int numOfLeds, int parts, CRGB color, int duration) {

  int i, steps, wait;

  steps = numOfLeds / parts;
  wait = duration / 2;

  for (i = 0; i < numOfLeds; i += steps) {

    leds[i] = color;
  }

  FastLED.show();
  delay(wait);

  for (i = 0; i < numOfLeds; i += steps) {

    leds[i] = CRGB::Black;
  }

  FastLED.show();
  delay(wait);
}


void JigglyLights::pulse(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int i, step, numOfSteps = 20;
  int red, green, blue;
  int tempRed, tempGreen, tempBlue;

  for(step = 0; step < numOfSteps; step++) {

    red = color.r;
    green = color.g;
    blue = color.b;

    tempRed = red - (step * (red / numOfSteps));
    tempGreen = green - (step * (green / numOfSteps));
    tempBlue = blue - (step * (blue / numOfSteps));

    for(i = 0; i < numOfLeds; i++) {
      leds[i] = CRGB(tempRed, tempGreen, tempBlue);
    }

    FastLED.show();
    delay(duration / numOfSteps);
  }
}


void JigglyLights::sparkleAt(int index, CRGB *leds, int numOfLeds, CRGB color, int duration) {

  if(index >= numOfLeds) {
    /* Out of bounds. */
  } else {
    int i, spread = 2, spreadIndex = 0;

    leds[index] = color;
    FastLED.show();

    for(i = 1; i <= spread; i++) {

      delay(duration / (spread + 1));

      if(index - (i - 1) >= 0) {
        leds[index - (i - 1)] = CRGB::Black;
      }

      if(index + (i - 1) < numOfLeds) {
        leds[index + (i - 1)] = CRGB::Black;
      }

      leds[index + i] = color;
      leds[index - i] = color;

      FastLED.show();
    }

    delay(duration / (spread + 1));

    if(index - (i - 1) >= 0) {
      leds[index - (i - 1)] = CRGB::Black;
    }

    if(index + (i - 1) < numOfLeds) {
      leds[index + (i - 1)] = CRGB::Black;
    }

    FastLED.show();
  }
}


void JigglyLights::sparkleAtRandomIndex(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int randomIndex = random8(numOfLeds);

  sparkleAt(randomIndex, leds, numOfLeds, color, duration);
}


void JigglyLights::flashyShit(CRGB *leds, int numOfLeds, int maxIntensity, int duration) {

  int i, randred, randgreen, randblue;
  int middle = numOfLeds / 2;

  for(i = 0; i < (numOfLeds / 2); i++) {
    randred = random8(maxIntensity);
    randgreen = random8(maxIntensity);
    randblue = random8(maxIntensity);

    leds[middle + i] = CRGB(randred, randgreen, randblue);
    leds[middle - i] = CRGB(randred, randgreen, randblue);
    FastLED.show();

    delay(duration / (numOfLeds / 2));

    leds[middle + i] = CRGB::Black;
    leds[middle - i] = CRGB::Black;

    FastLED.show();
  }

  for(i = (numOfLeds / 2); i >= 0; i--) {

    randred = random8(maxIntensity);
    randgreen = random8(maxIntensity);
    randblue = random8(maxIntensity);

    leds[middle + i] = CRGB(randred, randgreen, randblue);
    leds[middle - i] = CRGB(randred, randgreen, randblue);
    FastLED.show();

    delay(duration / (numOfLeds / 2));

    leds[middle + i] = CRGB::Black;
    leds[middle - i] = CRGB::Black;

    FastLED.show();
  }
}


void JigglyLights::randomIndexFill(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int ledsOn[numOfLeds];
  int randomIndex, onCounter = 0;

  memset(ledsOn, 0, sizeof(ledsOn));

  while(onCounter < numOfLeds) {

    randomIndex = random8(numOfLeds);

    if(ledsOn[randomIndex] == 0) {
      leds[randomIndex] = color;
      FastLED.show();

      ledsOn[randomIndex] = 1;
      onCounter++;

      delay(duration / numOfLeds);
    }
  }

  clearAll(leds, numOfLeds);
}


void JigglyLights::transition(CRGB *leds, int numOfLeds, CRGB firstColor, CRGB secondColor, int duration) {

  int i, wait, deltaRed, deltaGreen, deltaBlue;

  wait = duration / 20;
  deltaRed = (secondColor.r - firstColor.r) / 20;
  deltaGreen = (secondColor.g - firstColor.g) / 20;
  deltaBlue = (secondColor.b - firstColor.b) / 20;

  for(i = 0; i < numOfLeds; i++) {

    leds[i] = firstColor;
  }

  FastLED.show();
  delay(wait);

  for(i = 0; i < numOfLeds; i++) {

    leds[i].r += deltaRed;
    leds[i].g += deltaGreen;
    leds[i].b += deltaBlue;
  }

  FastLED.show();
  delay(wait);

  for(i = 0; i < numOfLeds; i++) {

    leds[i].setRGB(0, 0, 0);
  }

  FastLED.show();
  delay(wait);
}


void JigglyLights::runAllAnimations(CRGB *leds, int numOfLeds, int maxIntensity, int durationEach) {

  runner(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  colorRunner(leds, numOfLeds, 255, durationEach);
  progressbar(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  progressbarCentered(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  blinking(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  blinkingParts(leds, numOfLeds,5, randomColor(maxIntensity), durationEach);
  pulse(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  sparkleAtRandomIndex(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  flashyShit(leds, numOfLeds,maxIntensity, durationEach);
  randomIndexFill(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  clearAll(leds, numOfLeds);
}
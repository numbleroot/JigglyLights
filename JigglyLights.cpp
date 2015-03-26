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

CRGB gradientColors[] = {
  CRGB(54,0,229), //blue
  CRGB(70,3,204),
  CRGB(87,7,179),
  CRGB(104,11,154), //purple
  CRGB(120,14,129),
  CRGB(137,18,104),
  CRGB(154,22,79),
  CRGB(170,25,54),
  CRGB(187,29,29),
  CRGB(204,33,5), //red
  CRGB(208,56,6),
  CRGB(213,80,8),
  CRGB(218,104,9),
  CRGB(222,127,11), //orange
  CRGB(227,151,12),
  CRGB(232,175,14),
  CRGB(236,198,15),
  CRGB(241,222,17),
  CRGB(246,246,19), //yellow
  CRGB(219,247,18),
  CRGB(192,248,17),
  CRGB(165,249,17),
  CRGB(138,250,16),
  CRGB(112,251,16),
  CRGB(85,252,15),
  CRGB(58,253,15),
  CRGB(31,254,14),
  CRGB(5,255,14), //green
  CRGB(4,240,39),
  CRGB(3,225,64),
  CRGB(3,210,98),
  CRGB(2,195,114),
  CRGB(2,181,139),
  CRGB(1,166,164),
  CRGB(1,151,189),
  CRGB(0,136,214),
  CRGB(0,122,240) //blue
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


int JigglyLights::calcMatrixIndex(int x, int y, int leds_x) {

    int res = (y * leds_x);
    leds_x--;

    if((y % 2) == 0) {
      res += x;
    }
    else {
      res += (leds_x - x);
    }

    return res;
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

    if (color){
      leds[i] = color;
    }else{//color is 0,0,0
      leds[i] = randomColor(255);
    }

    FastLED.show();
    delay(wait);

    leds[i] = CRGB::Black;
    FastLED.show();
  }

  for(i = (numOfLeds - 1); i > 0; i--) {

    if (color){
      leds[i] = color;
    }else{
      leds[i] = randomColor(255);
    }

    FastLED.show();
    delay(wait);

    leds[i] = CRGB::Black;
    FastLED.show();
  }
}

void JigglyLights::progressbar(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int i, wait;

  wait = duration / (numOfLeds * 4);

  for(i = 0; i < numOfLeds; i++) {

    if (color){
      leds[i] = color;
    }else{//color is 0,0,0
      leds[i] = randomColor(255);
    }

    FastLED.show();
    delay(wait);
  }

  for(i = 0; i < numOfLeds; i++) {

    leds[i] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }

  for(i = numOfLeds; i >= 0; i--) {

    if (color){
      leds[i] = color;
    }else{//color is 0,0,0
      leds[i] = randomColor(255);
    }
    FastLED.show();
    delay(wait);
  }

  for(i = numOfLeds; i >= 0; i--) {

    leds[i] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }
}


void JigglyLights::progressbarCentered(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int i, center, inv, wait;

  center = numOfLeds / 2;
  wait = duration / (numOfLeds * 2);

  for(i = center; i < numOfLeds; i++) {

    inv = (numOfLeds - i) - 1;

    if (color){
      leds[i] = color;
    }else{//color is 0,0,0
      leds[i] = randomColor(255);
    }

    if (color){
      leds[inv] = color;
    }else{//color is 0,0,0
      leds[inv] = randomColor(255);
    }

    FastLED.show();
    delay(wait);
  }

  for(i = (numOfLeds - 1); i >= center; i--) {

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

  for(i = 0; i < numOfLeds; i++) {
    if (color){
      leds[i] = color;
    }else{//color is 0,0,0
      leds[i] = randomColor(255);
    }
  }

  FastLED.show();
  delay(wait);

  for(i = 0; i < numOfLeds; i++) {

    leds[i] = CRGB::Black;
  }

  FastLED.show();
  delay(wait);
}


void JigglyLights::blinkingParts(CRGB *leds, int numOfLeds, int parts, CRGB color, int duration) {

  int i, steps, wait;

  steps = numOfLeds / parts;
  wait = duration / 2;

  for(i = 0; i < numOfLeds; i += steps) {
    if (color){
      leds[i] = color;
    }else{//color is 0,0,0
      leds[i] = randomColor(255);
    }
  }

  FastLED.show();
  delay(wait);

  for(i = 0; i < numOfLeds; i += steps) {

    leds[i] = CRGB::Black;
  }

  FastLED.show();
  delay(wait);
}


void JigglyLights::glow(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int i, u, highest;

  highest = color.r;

  if(color.b > highest) {
    highest = color.b;
  }

  if(color.g > highest) {
    highest = color.g;
  }

  for(i = 0; i < numOfLeds; i++) {

    leds[i] = color;
  }

  FastLED.show();
  delay(duration / 5);


  for(u = highest; u > 1; u--) {

    for(i = 0; i < numOfLeds; i++) {

      leds[i].r = (leds[i].r-- > 1) ? leds[i].r-- : 1;
      leds[i].g = (leds[i].g-- > 1) ? leds[i].g-- : 1;
      leds[i].b = (leds[i].b-- > 1) ? leds[i].b-- : 1;
    }

    FastLED.show();
    delay(30);
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


void JigglyLights::gradientLoop(CRGB *leds, int numOfLeds, int brightness, int duration) {

  int i, j, gradientColorCount, durationEach;

  gradientColorCount = sizeof(gradientColors) / sizeof(gradientColors[0]);
  durationEach = duration / gradientColorCount;

  if(brightness < 0) {
    brightness = 0;
  }
  else if(brightness > 255) {
    brightness = 255;
  }

  FastLED.setBrightness(brightness);

  for(i = 0; i < gradientColorCount; i++) {

    /* Set all LEDs. */
    for(j = 0; j < numOfLeds; j++) {
      leds[j] = gradientColors[i];
    }

    FastLED.show();
    delay(durationEach);
  }

  clearAll(leds, numOfLeds);
}


void JigglyLights::runAllAnimations(CRGB *leds, int numOfLeds, int maxIntensity, int durationEach) {

  runner(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  progressbar(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  progressbarCentered(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  blinking(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  blinkingParts(leds, numOfLeds, 5, randomColor(maxIntensity), durationEach);
  glow(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  sparkleAtRandomIndex(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  flashyShit(leds, numOfLeds,maxIntensity, durationEach);
  randomIndexFill(leds, numOfLeds, randomColor(maxIntensity), durationEach);
  gradientLoop(leds, numOfLeds, maxIntensity, durationEach);
  clearAll(leds, numOfLeds);
}


void JigglyLights::chimes(CRGB *leds, int numOfLeds) {

  int i;

  runner(leds, numOfLeds, CRGB(70, 0, 100), 6600);
  runner(leds, numOfLeds, CRGB(100, 60, 10), 6600);

  flashyShit(leds, numOfLeds, 50, 6600);
  flashyShit(leds, numOfLeds, 50, 6600);

  progressbarCentered(leds, numOfLeds, CRGB(30, 0, 100), 3300);
  delay(390);
  for(i = 0; i < 3; i++) {
    blinking(leds, numOfLeds, CRGB(0, 60, 100), 200);
  }
  blinking(leds, numOfLeds, CRGB(0, 60, 100), 300);
  blinking(leds, numOfLeds, CRGB(0, 60, 100), 210);

  progressbarCentered(leds, numOfLeds, CRGB(100, 0, 0), 3300);
  delay(395);
  for(i = 0; i < 3; i++) {
    blinking(leds, numOfLeds, CRGB(100, 20, 20), 200);
  }
  blinking(leds, numOfLeds, CRGB(100, 20, 20), 300);
  blinking(leds, numOfLeds, CRGB(100, 20, 20), 210);

  progressbarCentered(leds, numOfLeds, CRGB(0, 100, 30), 3300);
  delay(395);
  for(i = 0; i < 3; i++) {
    blinking(leds, numOfLeds, CRGB(0, 100, 40), 200);
  }
  blinking(leds, numOfLeds, CRGB(0, 100, 40), 300);
  blinking(leds, numOfLeds, CRGB(0, 100, 40), 210);
  delay(10000);
}


void JigglyLights::matrixWave(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration) {

  int i, x, y, ledIndex, stateIndex, limit = (2 * (leds_y - 1));
  int blinks[limit];

  for(x = 0; x < leds_y; x++) {

    blinks[x] = (x + 1);

    if(x != 0) {
      blinks[(limit - x)] = (x + 1);
    }
  }

  for(i = (limit - 1); i >= 0; i--) {

    for(x = 0; x < leds_x; x++) {

      for(y = 0; y < leds_y; y++) {

        ledIndex = calcMatrixIndex(x, y, leds_x);
        stateIndex = (x + i) % limit;

        if(y < blinks[stateIndex]) {
          leds[ledIndex] = color;
        }
        else {
          leds[ledIndex] = CRGB(0, 0, 0);
        }
      }
    }

    FastLED.show();
    delay(duration / leds_x);
  }
}


void JigglyLights::matrixWaveInverted(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration) {

  int i, x, y, ledIndex, stateIndex, limit = (2 * (leds_y - 1));
  int blinks[limit];

  for(x = 0; x < leds_y; x++) {

    blinks[x] = (x + 1);

    if(x != 0) {
      blinks[(limit - x)] = (x + 1);
    }
  }

  for(i = 0; i < limit; i++) {

    for(x = 0; x < leds_x; x++) {

      for(y = 0; y < leds_y; y++) {

        ledIndex = calcMatrixIndex(x, y, leds_x);
        stateIndex = (x + i) % limit;

        if(y < blinks[stateIndex]) {
          leds[ledIndex] = color;
        }
        else {
          leds[ledIndex] = CRGB(0, 0, 0);
        }
      }
    }

    FastLED.show();
    delay(duration / leds_x);
  }
}


void JigglyLights::matrixWaveOne(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration) {

  int i, x, y, index;

  for(i = 0; i < leds_x; i++) {

    for(x = 0; x < leds_x; x++) {

      for(y = 0; y < leds_y; y++) {

        index = calcMatrixIndex(x, y, leds_x);

        if(i == x) {
          leds[index] = color;
        }
        else {
          leds[index] = CRGB(0, 0, 0);
        }
      }
    }

    FastLED.show();
    delay(duration / leds_x);
  }
}


void JigglyLights::matrixWaveOneRandom(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration) {

  int i, x, y, randAmount, index;

  for(i = 0; i < leds_x; i++) {

    for(x = 0; x < leds_x; x++) {

      randAmount = random8(leds_y + 1);

      for(y = 0; y < leds_y; y++) {

        index = calcMatrixIndex(x, y, leds_x);

        if((i == x) && (y < randAmount)) {
          leds[index] = color;
        }
        else {
          leds[index] = CRGB(0, 0, 0);
        }
      }
    }

    FastLED.show();
    delay(duration / leds_x);
  }
}


void JigglyLights::matrixProgressbar(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration) {

  int i, x, y, index, wait;

  wait = duration / (4 * leds_x);

  for(i = 0; i < leds_x; i++) {

    for(x = 0; x < leds_x; x++) {

      for(y = 0; y < leds_y; y++) {

        index = calcMatrixIndex(x, y, leds_x);

        if(x < i) {
          leds[index] = color;
        }
        else {
          leds[index] = CRGB(0, 0, 0);
        }
      }
    }

    FastLED.show();
    delay(wait);
  }

  for(i = 0; i < leds_x; i++) {

    for(x = 0; x < leds_x; x++) {

      for(y = 0; y < leds_y; y++) {

        index = calcMatrixIndex(x, y, leds_x);

        if(x > i) {
          leds[index] = color;
        }
        else {
          leds[index] = CRGB(0, 0, 0);
        }
      }
    }

    FastLED.show();
    delay(wait);
  }

  for(i = (leds_x - 1); i >= 0; i--) {

    for(x = (leds_x - 1); x >= 0; x--) {

      for(y = (leds_y - 1); y >= 0; y--) {

        index = calcMatrixIndex(x, y, leds_x);

        if(x > i) {
          leds[index] = color;
        }
        else {
          leds[index] = CRGB(0, 0, 0);
        }
      }
    }

    FastLED.show();
    delay(wait);
  }

  for(i = (leds_x - 1); i >= 0; i--) {

    for(x = (leds_x - 1); x >= 0; x--) {

      for(y = (leds_y - 1); y >= 0; y--) {

        index = calcMatrixIndex(x, y, leds_x);

        if(x < i) {
          leds[index] = color;
        }
        else {
          leds[index] = CRGB(0, 0, 0);
        }
      }
    }

    FastLED.show();
    delay(wait);
  }
}


void JigglyLights::matrixProgressbarCentered(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration) {

  int i, x, y, center, index, invIndex, wait;

  center = leds_x / 2;
  wait = duration / (4 * leds_x);

  for(i = center; i < leds_x; i++) {

    for(x = 0; x < leds_x; x++) {

      for(y = 0; y < leds_y; y++) {

        index = calcMatrixIndex(x, y, leds_x);
        invIndex = calcMatrixIndex(((leds_x - x) - 1), y, leds_x);

        if(x <= i) {
          leds[index] = color;
          leds[invIndex] = color;
        }
        else {
          leds[index] = CRGB(0, 0, 0);
          leds[invIndex] = CRGB(0, 0, 0);
        }
      }
    }

    FastLED.show();
    delay(wait);
  }

  for(i = (leds_x - 1); i > center; i--) {

    for(x = 0; x < leds_x; x++) {

      for(y = 0; y < leds_y; y++) {

        index = calcMatrixIndex(x, y, leds_x);
        invIndex = calcMatrixIndex(((leds_x - x) - 1), y, leds_x);

        if(x <= i) {
          leds[index] = color;
          leds[invIndex] = color;
        }
        else {
          leds[index] = CRGB(0, 0, 0);
          leds[invIndex] = CRGB(0, 0, 0);
        }
      }
    }

    FastLED.show();
    delay(wait);
  }
}


void JigglyLights::matrixLevel(CRGB *leds, int leds_x, int leds_y, CRGB color, int duration) {

  int x, y, index;

  for(y = 0; y < leds_y; y++) {

    for(x = 0; x < leds_x; x++) {

      index = calcMatrixIndex(x, y, leds_x);

      leds[index] = color;
    }

    FastLED.show();
    delay(duration / leds_y);
  }

  for(y = (leds_y - 1); y >= 0; y--) {

    for(x = 0; x < leds_x; x++) {

      index = calcMatrixIndex(x, y, leds_x);

      leds[index] = CRGB(0, 0, 0);
    }

    FastLED.show();
    delay(duration / leds_y);
  }
}
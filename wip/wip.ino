#include <FastLED.h>


#define PIN 6
#define NUM_LEDS 31

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {
  runAllAnimations(leds, NUM_LEDS, 40, 3500);
}

void runner(CRGB *leds, int numOfLeds, CRGB color, int duration) {

  int i, wait;

  wait = duration / (numOfLeds * 2);

  for (i = 0; i < numOfLeds; i++) {

    leds[i] = color;
    FastLED.show();
    delay(wait);
    leds[i] = CRGB::Black;
    FastLED.show();
  }

  for (i = (numOfLeds - 1); i > 0; i--) {

    leds[i] = color;
    FastLED.show();
    delay(wait);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}

void progressbar(CRGB *leds, int numOfLeds, CRGB color, int duration) {

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

void progressbarCentered(CRGB *leds, int numOfLeds, CRGB color, int duration) {

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

void blinking(CRGB *leds, int numOfLeds, CRGB color, int duration) {

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

void blinkingParts(CRGB *leds, int numOfLeds, int parts, CRGB color, int duration) {

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

//ms = time of pulse
void pulse(CRGB *leds, int numOfLeds, CRGB color, int ms) {
  int numOfSteps = 20;

  for (int step = 0; step < numOfSteps; step++) {

    int red = color.r;
    int green = color.g;
    int blue = color.b;

    int tempRed = red - (step * (red / numOfSteps));
    int tempGreen = green - (step * (green / numOfSteps));
    int tempBlue = blue - (step * (blue / numOfSteps));

    for (int i = 0; i < numOfLeds; i++) {
      leds[i] = CRGB(tempRed, tempGreen, tempBlue);
    }

    FastLED.show();
    delay(ms / numOfSteps);
  }
}


void sparkleAt(int index, CRGB *leds, int numOfLeds, CRGB color, int ms){
  if (index >= numOfLeds){
    //out of bounds
  }else{
    int spread = 2;
    int spreadIndex = 0;

    leds[index] = color;
    FastLED.show();

    int i;
    for (i =  1; i <= spread; i++){
      delay(ms/(spread+1));
      if (index - (i-1)>=0){
        leds[index - (i-1)] = CRGB::Black;
      }

      if (index + (i-1)<numOfLeds){
        leds[index + (i-1)] = CRGB::Black;
      }

      leds[index + i] = color;
      leds[index - i] = color;

      FastLED.show();
    }

     delay(ms/(spread+1));
      if (index - (i-1)>=0){
        leds[index - (i-1)] = CRGB::Black;
      }

      if (index + (i-1)<numOfLeds){
        leds[index + (i-1)] = CRGB::Black;
      }

      FastLED.show();

  }
}

void sparkleAtRandomIndex(CRGB *leds, int numOfLeds, CRGB color, int ms){
  int randomIndex = random8(numOfLeds);
  sparkleAt(randomIndex, leds, numOfLeds, color, ms);
}

void flashyShit(CRGB *leds, int numOfLeds, int maxIntensity, int ms){
  int middle = numOfLeds / 2;
  int randred,randgreen,randblue;
  
  for (int i = 0; i < numOfLeds / 2; i ++){
    randred = random8(maxIntensity);
    randgreen = random8(maxIntensity);
    randblue = random8(maxIntensity);
    
    leds[middle + i] = CRGB(randred,randgreen,randblue);
    leds[middle - i] = CRGB(randred,randgreen,randblue);
    FastLED.show();
    delay(ms / (numOfLeds / 2));
    
    leds[middle + i] = CRGB::Black;
    leds[middle - i] = CRGB::Black;
    FastLED.show();
  }
  
  for (int i = numOfLeds / 2; i >= 0; i --){
    randred = random8(maxIntensity);
    randgreen = random8(maxIntensity);
    randblue = random8(maxIntensity);
    
    leds[middle + i] = CRGB(randred,randgreen,randblue);
    leds[middle - i] = CRGB(randred,randgreen,randblue);
    FastLED.show();
    delay(ms / (numOfLeds / 2));
    
    leds[middle + i] = CRGB::Black;
    leds[middle - i] = CRGB::Black;
    FastLED.show();
  
  }
}

void randomIndexFill(CRGB *leds, int numOfLeds, CRGB color, int ms){
  int ledsOn[numOfLeds];
  memset(ledsOn, 0, sizeof(ledsOn));
  int onCounter = 0;

  while (onCounter < numOfLeds){
    int randomIndex = random8(numOfLeds);
    if (ledsOn[randomIndex] == 0){
      leds[randomIndex] = color;
      FastLED.show();
      
      ledsOn[randomIndex] = 1;
      onCounter ++;
      
      delay(ms / numOfLeds);
    }

  }
  
  clearAll(leds, numOfLeds);
  

}

void clearAll(CRGB *leds, int numOfLeds){
  for (int i = 0; i < numOfLeds; i++){
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

CRGB randomColor(int maxIntensity){
  if (maxIntensity <= 255){
    int randred = random8(maxIntensity);
    int randgreen = random8(maxIntensity);
    int randblue = random8(maxIntensity);

    return CRGB(randred, randgreen, randblue);
  }else{
    // u stupid
    return CRGB::Black;
  }

}

void runAllAnimations(CRGB *leds, int numOfLeds, int maxIntensity, int durationEach){

  runner(leds, numOfLeds, randomColor(maxIntensity), durationEach);
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
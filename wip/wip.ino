#include <FastLED.h>


#define PIN 6
#define NUM_LEDS 31

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {
  // int randred = random8(100);
  // int randgreen = random8(100);
  // int randblue = random8(100);
  // progressbar(leds, NUM_LEDS, randred,randgreen,randblue, 30);
  // randred = random8(100);
  // randgreen = random8(100);
  // randblue = random8(100);
  // runner(leds, NUM_LEDS, randred,randgreen,randblue, 30);
  // randred = random8(100);
  // randgreen = random8(100);
  // randblue = random8(100);
  // blinking(leds, NUM_LEDS, randred,randgreen,randblue, 800);
  // randred = random8(100);
  // randgreen = random8(100);
  // randblue = random8(100);
  // blinking(leds, NUM_LEDS, randred,randgreen,randblue, 800);
  // randred = random8(100);
  // randgreen = random8(100);
  // randblue = random8(100);
  // blinking(leds, NUM_LEDS, randred,randgreen,randblue, 800);
  // randred = random8(100);
  // randgreen = random8(100);
  // randblue = random8(100);
  // progressbarCentered(leds, NUM_LEDS, randred,randgreen,randblue, 30);
  // randred = random8(100);
  // randgreen = random8(100);
  // randblue = random8(100);
  // runner(leds, NUM_LEDS, randred,randgreen,randblue, 30);

//  sparkleAt(10, leds, NUM_LEDS, 25, 0, 0, 1000);
//  sparkleAtRandomIndex(leds, NUM_LEDS, 25, 0, 0, 500);


//  for (int i = 0; i < NUM_LEDS; i++){
//    sparkleAt(i, leds, NUM_LEDS, 0, 0, 25, 350);
//  }
//  
//  for (int i = (NUM_LEDS - 1); i >=0; i--){
//    sparkleAt(i, leds, NUM_LEDS, 0, 0, 25, 350);
//  }

//  flashyShit(leds, NUM_LEDS, 2000);
//  int randred = random8(50);
//  int randgreen = random8(50);
//  int randblue = random8(50);
//  randomIndexFill(leds, NUM_LEDS, 0, 30, 10, 2600);

//  void sparkleAt(int index, CRGB *leds, int numOfLeds, int red, int green, int blue, int ms){


//  for (int i = 0; i < NUM_LEDS; i++){
//    sparkleAt(i, leds, NUM_LEDS, 0, 0, 25, 350);
//  }
//
//  for (int i = (NUM_LEDS - 1); i >=0; i--){
//  sparkleAt(i, leds, NUM_LEDS, 0, 0, 25, 350);
//  }
  
//  CRGB test = CRGB(10,10,10);
//  
//  for (int i = 0; i < NUM_LEDS; i++){
//    leds[i] = test;
//    FastLED.show();
//    delay(500);
//  }
//  
//  clearAll(leds, NUM_LEDS);
  runner(leds, NUM_LEDS, CRGB(10,0,20), 3000);
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

void flashyShit(CRGB *leds, int numOfLeds, int ms, int maxIntensity){
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

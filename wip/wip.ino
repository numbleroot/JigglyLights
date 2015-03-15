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

  flashyShit(leds, NUM_LEDS, 2000);

//  void sparkleAt(int index, CRGB *leds, int numOfLeds, int red, int green, int blue, int ms){

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

void progressbarCentered(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms) {

    int i, center, inv;

    center = numOfLeds / 2;
    
    for(i = center; i < numOfLeds; i++) {
    
        inv = (numOfLeds - i) - 1;
        leds[i].setRGB(red, green, blue);
        leds[inv].setRGB(red, green, blue);
        FastLED.show();
        delay(ms);
    }
    
    for(i = (numOfLeds - 1); i >= center; i--) {
    
        inv = (numOfLeds - i) - 1;
        leds[i].setRGB(0, 0, 0);
        leds[inv].setRGB(0, 0, 0);
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

void blinkingParts(CRGB *leds, int numOfLeds, int parts, int red, int green, int blue, int ms) {

    int i, steps;

    steps = numOfLeds / parts;

    for(i = 0; i < numOfLeds; i += steps) {

        leds[i].setRGB(red, green, blue);
    }

    FastLED.show();
    delay(ms);

    for(i = 0; i < numOfLeds; i += steps) {

        leds[i].setRGB(0, 0, 0);
    }

    FastLED.show();
    delay(ms);
}

//ms = time of pulse
void pulse(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms){
  int numOfSteps = 20;

  for (int step = 0; step < numOfSteps; step++){

    int tempRed = red - (step * (red / numOfSteps));
    int tempGreen = green - (step * (green / numOfSteps));
    int tempBlue = blue - (step * (blue / numOfSteps));

    for (int i = 0; i < numOfLeds; i++){
      leds[i].setRGB(tempRed, tempGreen, tempBlue); 
    }
    
    FastLED.show();
    delay(ms/numOfSteps);
  }
}


void sparkleAt(int index, CRGB *leds, int numOfLeds, int red, int green, int blue, int ms){
  if (index >= numOfLeds){
    //out of bounds
  }else{
    int spread = 2;
    int spreadIndex = 0;

    leds[index].setRGB(red, green, blue);
    FastLED.show();
    
    int i;
    for (i =  1; i <= spread; i++){
      delay(ms/(spread+1));
      if (index - (i-1)>=0){
        leds[index - (i-1)].setRGB(0,0,0);
      }
      
      if (index + (i-1)<numOfLeds){
        leds[index + (i-1)].setRGB(0,0,0);
      }
      
      leds[index + i].setRGB(red, green, blue);
      leds[index - i].setRGB(red, green, blue);
      
      FastLED.show();
    }
    
     delay(ms/(spread+1));
      if (index - (i-1)>=0){
        leds[index - (i-1)].setRGB(0,0,0);
      }
      
      if (index + (i-1)<numOfLeds){
        leds[index + (i-1)].setRGB(0,0,0);
      }
      
      FastLED.show();
      
  }
}

void sparkleAtRandomIndex(CRGB *leds, int numOfLeds, int red, int green, int blue, int ms){
  int randomIndex = random8(numOfLeds);
  sparkleAt(randomIndex, leds, numOfLeds, red, green, blue, ms);
}

void flashyShit(CRGB *leds, int numOfLeds, int ms){
  int middle = numOfLeds / 2;
  int randred,randgreen,randblue;
  
  for (int i = 0; i < numOfLeds / 2; i ++){
    randred = random8(7);
    randgreen = random8(7);
    randblue = random8(7);
    
    leds[middle + i].setRGB(randred,randgreen,randblue);
    leds[middle - i].setRGB(randred,randgreen,randblue);
    FastLED.show();
    delay(ms / (numOfLeds / 2));
    
    leds[middle + i].setRGB(0,0,0);
    leds[middle - i].setRGB(0,0,0);
    FastLED.show();
  }
  
  for (int i = numOfLeds / 2; i >= 0; i --){
    randred = random8(7);
    randgreen = random8(7);
    randblue = random8(7);
    
    leds[middle + i].setRGB(randred,randgreen,randblue);
    leds[middle - i].setRGB(randred,randgreen,randblue);
    FastLED.show();
    delay(ms / (numOfLeds / 2));
    
    leds[middle + i].setRGB(0,0,0);
    leds[middle - i].setRGB(0,0,0);
    FastLED.show();
  
  }
}

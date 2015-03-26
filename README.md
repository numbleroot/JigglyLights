# JigglyLights

JigglyLights is an LED animation library for the WS2812b LED strip (and strips of similar kind), executed through an Arduino controller. It is based on the [FastLED Arduino library](http://fastled.io/).

## Setup
* Clone the repo to a location of choice  
`git clone https://github.com/lenny-code/JigglyLights.git`
* Include the repo as a Library through the Arduino IDE  
 'Sketch > Import Library... > Add Library...'
* Add `#include <JigglyLights.h>` to your .ino file

* Clone and include the [FastLED library](https://github.com/FastLED/FastLED).  
* Add your LED strip in the setup() - function (like [this](https://github.com/FastLED/FastLED#simple-example))  

## Basic usage

```C++
JigglyLights jiggly;
jiggly.runner(leds, NUM_LEDS, CRGB::Red, 1000);
```

See [JigglyLights.h](https://github.com/lenny-code/JigglyLights/blob/master/JigglyLights.h) for animations and their specific usage.
 
## Example

```C++
#include <FastLED.h>
#include <JigglyLights.h>

/* The GPIO PIN you've attached the LED strip to. */
#define PIN 6

/* Number of LEDs of your strip. */
#define NUM_LEDS 31

/* LED array to individually address LEDs. */
CRGB leds[NUM_LEDS];
/* Jiggly instance to call the functions from. */
JigglyLights jiggly;


void setup() {
  /* See FastLED repo for details. */
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {

  /* Call JigglyLights animations through an instance like this. */
  jiggly.runner(leds, NUM_LEDS, CRGB::Red, 1000);

  /* See JigglyLights.h for animation documentation. */
}
```

You can find this example directly as an .ino file in this repo: [jiggly-example.ino](https://github.com/lenny-code/JigglyLights/blob/master/jiggly-example.ino).

## Third party library used

JigglyLights depends on the incredible [FastLED library](https://github.com/FastLED/FastLED).
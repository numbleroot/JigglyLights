# JigglyLights

JigglyLights is an LED animation library for the WS2812 LED strip (and strips of similar kind), executed through an Arduino controller.
It is based on the [FastLED Arduino library](http://fastled.io/).

##Setup
* Clone the repo to a location of choice  
`git clone https://github.com/lenny-code/JigglyLights.git`
* Include the repo as a Library through the Arduino IDE  
 'Sketch > Import Library... > Add Library...'
* Add `#include <JigglyLights.h>` to your .ino file

* Clone and include the [FastLED library](https://github.com/FastLED/FastLED).  
* Add your LED strip in the setup() - function (like [this](https://github.com/FastLED/FastLED#simple-example))  

##Basic usage
 `JigglyLights jiggly;`  
 `jiggly.runner(leds, NUM_LEDS, CRGB::Red, 1000);`  
 
 See [JigglyLights.h](https://github.com/lenny-code/JigglyLights/blob/master/JigglyLights.h) for animations and their specific usage.
 
##Example
See [jiggly-example.ino](https://github.com/lenny-code/JigglyLights/blob/master/jiggly-example.ino) for an example of how to use the library functions

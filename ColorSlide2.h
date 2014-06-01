// ColorSlide2.h

#ifndef _COLORSLIDE2_h
#define _COLORSLIDE2_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "FastLED.h"
#include "Pattern.h"

class ColorSlide2 : public Pattern
{
 protected:


 public:
	 ColorSlide2(CRGB *leds, long duration, int speed, int postDelay);
	 void draw();

};

#endif

// ColorSlide.h

#ifndef _COLORSLIDE_h
#define _COLORSLIDE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "FastLED.h"
#include "Pattern.h"

class ColorSlide : public Pattern
{
 protected:


 public:
	 ColorSlide(CRGB *leds, long duration, int speed, int postDelay);
	 void draw();

};

#endif


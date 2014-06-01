// AlphaTest.h

#ifndef _ALPHATEST_h
#define _ALPHATEST_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "FastLED.h"
#include "Pattern.h"

class AlphaTest : public Pattern
{
 protected:


 public:
	 AlphaTest(CRGB *leds, long duration, int speed, int postDelay);
	 void draw();

};

#endif


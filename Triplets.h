// Triplets.h

#ifndef _TRIPLETS_h
#define _TRIPLETS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "FastLED.h"
#include "Pattern.h"

class Triplets : public Pattern
{
 protected:


 public:
	 Triplets(CRGB *leds, long duration, int speed, int postDelay);
	 virtual void draw();

};

#endif


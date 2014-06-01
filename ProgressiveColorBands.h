// ProgressiveColorBands.h

#ifndef _PROGRESSIVECOLORBANDS_h
#define _PROGRESSIVECOLORBANDS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "FastLED.h"
#include "Pattern.h"

class ProgressiveColorBands : public Pattern
{
 protected:


 public:
	 ProgressiveColorBands(CRGB *leds, long duration, int speed, int postDelay);
	 void draw();
};

#endif


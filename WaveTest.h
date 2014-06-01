// WaveTest.h

#ifndef _WAVETEST_h
#define _WAVETEST_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "FastLED.h"
#include "Pattern.h"

class WaveTest : public Pattern
{
 protected:


 public:
	 WaveTest(CRGB *leds, long duration, int speed, int postDelay);
	 void draw();
};

#endif


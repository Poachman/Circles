// Dev.h

#ifndef _DEV_h
#define _DEV_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "FastLED.h"
#include "Pattern.h"

class Dev : public Pattern
{
 protected:
	 void jasonTest();
	 void jasonTestTwo();
	 int idex;
	 int iHue;

 public:
	 Dev(CRGB *leds, long duration, int speed, int postDelay);
	 virtual void draw();
	 void movingPattern();
	 void colorPalette();
	 void cubicEasingTest();
	 void alphaTestPattern();
	 void propTest();
	 void fadeTest();
	 void movingBlack();
	 void oneCycleTest();
	 void sineCircles();

};

#endif

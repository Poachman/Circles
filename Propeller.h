// Propeller.h

#ifndef _PROPELLER_h
#define _PROPELLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "FastLED.h"
#include "Pattern.h"

class Propeller : public Pattern
{
 protected:
	 uint8_t m_Segments;
	 bool m_RotationDirection;
	 bool m_BlackSpaces;


 public:
	 Propeller(CRGB *leds, long duration, int speed, int postDelay, uint8_t segments, bool rotationDirection, bool blackSpaces);
	 virtual void draw();

};

#endif


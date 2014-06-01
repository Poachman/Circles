// Pattern.h

#ifndef _PATTERN_h
#define _PATTERN_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "FastLED.h"
#include "Constants.h"

class Pattern
{
 protected:
	CRGB* m_pLeds;								// Pointer to the array of LEDs
	long m_Duration;							// Desired duration for the pattern, in milliseconds
	int m_Speed;								// Desired "speed" of the pattern (really, the delay between frames)
	int m_PostDelay;							// How long to hold on the final frame of the pattern, in milliseconds
	int m_OutTransition;						// Desired outgoing transition (used to clear the current pattern from the matrix)

	CRGB ledsLeft[LEDS_PER_STRIP];
	CRGB ledsTop[LEDS_PER_STRIP];
	CRGB ledsRight[LEDS_PER_STRIP];
	CRGB ledsBottom[LEDS_PER_STRIP];

	void shuffle (CHSV *t, int n);
	void shuffleColors();
	void updateDisplay(bool sendToOutput);
	void blankCircleArrays();
	void blankDisplay();

 public:
	Pattern(CRGB *leds, long duration, int speed, int postDelay);
	virtual void draw() {};

};

extern CHSV colorsH[];
//extern CRGB ledsLeft[];
//extern CRGB ledTop[];
//extern CRGB ledsRight[];
//extern CRGB ledsBottom[];

#endif


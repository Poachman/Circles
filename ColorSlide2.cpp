// 
// 
// 

#include "ColorSlide2.h"

ColorSlide2::ColorSlide2(CRGB *leds, long duration, int speed, int postDelay) : Pattern::Pattern(leds, duration, speed, postDelay) {}

void ColorSlide2::draw()
{
	unsigned long endTime = millis() + 15000;

	fill_solid(ledsTop, LEDS_PER_STRIP, hPurple);

	while (millis() < endTime)
	{

		for (int i = 0; i < LEDS_PER_STRIP / 2; i++)
		{
			ledsTop[i] = hYellow;
			ledsTop[i + (LEDS_PER_STRIP / 2)] = hGreen;
			ledsBottom[i] = hYellow;
			ledsBottom[i + (LEDS_PER_STRIP / 2)] = hGreen;
			ledsLeft[i] = hYellow;
			ledsLeft[i + (LEDS_PER_STRIP / 2)] = hGreen;
			ledsRight[i] = hYellow;
			ledsRight[i + (LEDS_PER_STRIP / 2)] = hGreen;
			updateDisplay(true);
			FastLED.delay(20);
		}

		for (int i = 0; i < LEDS_PER_STRIP / 2; i++)
		{
			ledsTop[i] = hPurple;
			ledsTop[i + (LEDS_PER_STRIP / 2)] = hPurple;
			ledsBottom[i] = hPurple;
			ledsBottom[i + (LEDS_PER_STRIP / 2)] = hPurple;
			ledsLeft[i] = hPurple;
			ledsLeft[i + (LEDS_PER_STRIP / 2)] = hPurple;
			ledsRight[i] = hPurple;
			ledsRight[i + (LEDS_PER_STRIP / 2)] = hPurple;
			updateDisplay(true);
			FastLED.delay(20);
		}

		for (int i = 0; i < LEDS_PER_STRIP / 2; i++)
		{
			ledsTop[i] = hGreen;
			ledsTop[i + (LEDS_PER_STRIP / 2)] = hYellow;
			ledsBottom[i] = hGreen;
			ledsBottom[i + (LEDS_PER_STRIP / 2)] = hYellow;
			ledsLeft[i] = hGreen;
			ledsLeft[i + (LEDS_PER_STRIP / 2)] = hYellow;
			ledsRight[i] = hGreen;
			ledsRight[i + (LEDS_PER_STRIP / 2)] = hYellow;
			updateDisplay(true);
			FastLED.delay(20);
		}

		for (int i = 0; i < LEDS_PER_STRIP / 2; i++)
		{
			ledsTop[i] = hPurple;
			ledsTop[i + (LEDS_PER_STRIP / 2)] = hPurple;
			ledsBottom[i] = hPurple;
			ledsBottom[i + (LEDS_PER_STRIP / 2)] = hPurple;
			ledsLeft[i] = hPurple;
			ledsLeft[i + (LEDS_PER_STRIP / 2)] = hPurple;
			ledsRight[i] = hPurple;
			ledsRight[i + (LEDS_PER_STRIP / 2)] = hPurple;
			updateDisplay(true);
			FastLED.delay(20);
		}
	}
}

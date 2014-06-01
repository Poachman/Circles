// 
// 
// 

#include "ColorSlide.h"

ColorSlide::ColorSlide(CRGB *leds, long duration, int speed, int postDelay) : Pattern::Pattern(leds, duration, speed, postDelay) {}

void ColorSlide::draw()
{
	int index = 0;
	int iHue = 255;
	unsigned long endTime = millis() + 30000;
	uint8_t barSize = 0;
	double desiredPeriodInSeconds = 3;

	while (millis() < endTime)
	{
		// Set the background color for each circle using a fill command
		fill_solid(ledsTop, LEDS_PER_STRIP, CHSV(iHue, 255, 255));
		fill_solid(ledsBottom, LEDS_PER_STRIP, CHSV(iHue, 255, 255));
		fill_solid(ledsLeft, LEDS_PER_STRIP, CHSV((iHue + 128) % 255, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS));
		fill_solid(ledsRight, LEDS_PER_STRIP, CHSV((iHue + 128) % 255, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS));

		barSize = (sin8(millis() / 4 / desiredPeriodInSeconds) / 64) + 3;			// an integer varying between 3 and 7

		// Now draw a complementing color as a set of opposite bands.
		for (int i = 0; i < barSize; i++)
		{
			ledsTop[(index + i) % LEDS_PER_STRIP] = CHSV((iHue + 128) % 255, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			ledsTop[(index + i + (LEDS_PER_STRIP / 2)) % LEDS_PER_STRIP] = CHSV((iHue + 128) % 255, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);

			ledsBottom[(index + i) % LEDS_PER_STRIP] = CHSV((iHue + 128) % 255, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			ledsBottom[(index + i + (LEDS_PER_STRIP / 2)) % LEDS_PER_STRIP] = CHSV((iHue + 128) % 255, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);

			ledsLeft[(index + i) % LEDS_PER_STRIP] = CHSV(iHue + 90, 255, 255);
			ledsLeft[(index + i + (LEDS_PER_STRIP / 2)) % LEDS_PER_STRIP] = CHSV(iHue + 90, 255, 255);

			ledsRight[(index + i) % LEDS_PER_STRIP] = CHSV(iHue + 90, 255, 255);
			ledsRight[(index + i + (LEDS_PER_STRIP / 2)) % LEDS_PER_STRIP] = CHSV(iHue + 90, 255, 255);
		}

		updateDisplay(true);

		iHue--;

		index++;
		FastLED.delay(50);
	}
}

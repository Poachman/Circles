// 
// 
// 

#include "ProgressiveColorBands.h"

ProgressiveColorBands::ProgressiveColorBands(CRGB *leds, long duration, int speed, int postDelay) : Pattern::Pattern(leds, duration, speed, postDelay) {}

void ProgressiveColorBands::draw()
{
	uint8_t hue = 0;
	uint8_t saturation = 255;
	uint8_t brightness = 255;

	uint8_t index = 0;
	uint8_t segments = 2;							// Desired number of segments (bands)

	// Repeat this several times, with an increasing number of sgements each time.
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < LEDS_PER_STRIP; i++)
		{
			//		ledsBottom[i] = CHSV(colorsH[index], DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			ledsTop[i] = CHSV(hue, saturation, brightness);
			ledsBottom[i] = CHSV(hue + 40, saturation, brightness);
			ledsLeft[i] = CHSV(hue + 80, saturation, brightness);
			ledsRight[i] = CHSV(hue + 120, saturation, brightness);

			// Since i is zero-based, but number of segments is 1-based, we need to use (i + 1) below.
			// Once we have lit up the number of LEDs corresponding to one segment, set the next LED black.
			// Actually, this sets the last LED in each segment to black.
			if ((i + 1) % (LEDS_PER_STRIP / segments) == 0)
			{
				hue += 255 / (segments + 1);
				saturation = 0;
				brightness = 0;
				index++;
			}
			else if ((i + 1) % 4 == 0)
			{
				//hue += 20;
				//saturation = 255;
				//index++;
			}
			else
			{
				saturation = DEFAULT_SATURATION;
				brightness = DEFAULT_BRIGHTNESS;
			}
		}

		updateDisplay(true);
		FastLED.delay(5000);

		// For all but the last iteration, add one to the number of segements (the progression is 2, 3, 4, 6).
		if (j < 2)
		{
			segments++;
		}
		else
		{
			segments += 2;
		}
	}
}


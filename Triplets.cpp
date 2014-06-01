// 
// 
// 

#include "Triplets.h"

Triplets::Triplets(CRGB *leds, long duration, int speed, int postDelay) : Pattern::Pattern(leds, duration, speed, postDelay) {}

void Triplets::draw()
{
	int lowerIndex;
	int upperIndex;
	uint8_t bgLeft = hGold.hue;
	uint8_t bgTop = hGold.hue;
	uint8_t bgRight = hGold.hue;
	uint8_t bgBottom = hGold.hue;

	blankDisplay();

	for (int k = 0; k < 8; k++)
	{
		for (int i = 0; i < (LEDS_PER_STRIP / 2); i++)
		{
			fill_solid(ledsLeft, LEDS_PER_STRIP, CHSV(bgLeft, 255, 100));
			fill_solid(ledsTop, LEDS_PER_STRIP, CHSV(bgTop, 255, 100));
			fill_solid(ledsRight, LEDS_PER_STRIP, CHSV(bgRight, 255, 100));
			fill_solid(ledsBottom, LEDS_PER_STRIP, CHSV(bgBottom, 255, 100));

			for (int j = 0; j < 5; j++)
			{
				lowerIndex = i + j;
				upperIndex = i + j + (LEDS_PER_STRIP / 2);
				if (upperIndex >= LEDS_PER_STRIP)
				{
					upperIndex = upperIndex - LEDS_PER_STRIP;
				}

				ledsLeft[lowerIndex] = hRed;
				ledsLeft[upperIndex] = hRed;

				ledsTop[lowerIndex] = hBlue;
				ledsTop[upperIndex] = hBlue;

				ledsRight[lowerIndex] = hGreen;
				ledsRight[upperIndex] = hGreen;

				ledsBottom[lowerIndex] = hPurple;
				ledsBottom[upperIndex] = hPurple;
			}

			updateDisplay(true);
			FastLED.delay(100);
			blankCircleArrays();
			blankDisplay();

			//bgLeft += 1;
			//bgTop += 1;
			//bgRight += 5;
		}
	}
}

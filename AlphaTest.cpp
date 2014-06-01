// 
// 
// 

#include "AlphaTest.h"

AlphaTest::AlphaTest(CRGB *leds, long duration, int speed, int postDelay) : Pattern::Pattern(leds, duration, speed, postDelay) {}

void AlphaTest::draw()
{
	CRGB ledsTEMP[LEDS_PER_STRIP];

	uint8_t r, g, b;
	double dR, dG, dB;
	uint8_t numberOfSteps = 20;

	//Dev *myDev;
	//myDev = new Dev(m_pLeds, 0, 0, 0);
	//myDev->alphaTestPattern();

	for (int k = 0; k < 4; k++)
	{
		shuffleColors();

		fill_solid(ledsTop, LEDS_PER_STRIP / 3, colorsH[0]);
		fill_solid(ledsTop + 12, LEDS_PER_STRIP / 3, colorsH[1]);
		fill_solid(ledsTop + 24, LEDS_PER_STRIP / 3, colorsH[2]);

		fill_solid(ledsBottom, LEDS_PER_STRIP / 6, colorsH[3]);
		fill_solid(ledsBottom + 6, LEDS_PER_STRIP / 6, colorsH[4]);
		fill_solid(ledsBottom + 12, LEDS_PER_STRIP / 6, colorsH[5]);
		fill_solid(ledsBottom + 18, LEDS_PER_STRIP / 6, colorsH[6]);
		fill_solid(ledsBottom + 24, LEDS_PER_STRIP / 6, colorsH[7]);
		fill_solid(ledsBottom + 30, LEDS_PER_STRIP / 6, colorsH[8]);

		// Copy the output array to a temp location
		for (int i = 0; i < LEDS_PER_STRIP; i++)
		{
			ledsTEMP[i] = ledsBottom[i];
			ledsLeft[i] = ledsBottom[i];
		}

		updateDisplay(true);

		// These two loops cause a dissolve from one circle to the other.
		for (double j = 0; j <= numberOfSteps; j++)
		{
			for (int i = 0; i < LEDS_PER_STRIP; i++)
			{
				// These three lines add a portion of each input array and write it to the output array.  The portions
				// move to progressively more and more of the output array during the "i" loop.  This is done purely
				// using color.  If the input arrays where CHSV, I could do this using value instead.
				r = (ledsTop[i].r * ((numberOfSteps - j) / numberOfSteps)) + (ledsTEMP[i].r * (j / numberOfSteps));
				g = (ledsTop[i].g * ((numberOfSteps - j) / numberOfSteps)) + (ledsTEMP[i].g * (j / numberOfSteps));
				b = (ledsTop[i].b * ((numberOfSteps - j) / numberOfSteps)) + (ledsTEMP[i].b * (j / numberOfSteps));

				ledsBottom[i].r = r;
				ledsBottom[i].g = g;
				ledsBottom[i].b = b;
			}

			updateDisplay(true);
			if (j == 1)
			{
				FastLED.delay(3000);
			}

			FastLED.delay(2000 / numberOfSteps);
		}

		FastLED.delay(3000);
		blankDisplay();
		FastLED.delay(1000);
	}
}

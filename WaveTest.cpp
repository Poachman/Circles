// 
// 
// 

#include "WaveTest.h"

WaveTest::WaveTest(CRGB *leds, long duration, int speed, int postDelay) : Pattern::Pattern(leds, duration, speed, postDelay) {}

void WaveTest::draw()
{
	uint8_t brightness1;
	uint8_t brightness2;
	unsigned long endTime;
	
	shuffleColors();

	endTime = millis() + 15000;

	while (millis() < endTime)
	{
		for (int i = 0; i < LEDS_PER_STRIP; i++)
		{
			//		brightness = (sin8(millis() * i) / 7) + 18;
			brightness1 = sin8((millis() / 50) * (i * 1));
			brightness2 = cos8((millis() / 20) * (i * 1));
			//brightness = quadwave8((millis() / 35) * (i * 1));
			//ledsTop[i] = CHSV(hGold.hue, DEFAULT_SATURATION, brightness);
			//ledsBottom[i] = CHSV(hRed.hue, DEFAULT_SATURATION, brightness);
			//ledsLeft[i] = CHSV(hSkyBlue.hue, DEFAULT_SATURATION, brightness);
			//ledsRight[i] = CHSV(hGreen.hue, DEFAULT_SATURATION, brightness);
			ledsTop[i] = CHSV(colorsH[0].hue, DEFAULT_SATURATION, brightness1);
			ledsBottom[i] = CHSV(colorsH[1].hue, DEFAULT_SATURATION, brightness1);
			ledsLeft[i] = CHSV(colorsH[2].hue, DEFAULT_SATURATION, brightness2);
			ledsRight[i] = CHSV(colorsH[3].hue, DEFAULT_SATURATION, brightness2);
		}

		updateDisplay(true);
//		FastLED.delay(100);
	}

	endTime = millis() + 12000;
	uint8_t activeLEDS;
	double desiredPeriodInSeconds = 1.5;

	while (millis() < endTime)
	{
		// In the following line, the period for one wave is 255.  As such, millis() / 16 means that there will be ~ 62 ticks per second.
		// This comes out to be a roughly four second period.  Then I need to divide it by (255 / LEDS_PER_STRIP) to get a number that
		// varies between 0 and LEDS_PER_STRIP.
		activeLEDS = quadwave8(millis() / 4 / desiredPeriodInSeconds) / (255 / LEDS_PER_STRIP);

		blankDisplay();

		for (int i = 0; i < activeLEDS; i++)
		{
			ledsTop[LEDS_PER_STRIP - i] = colorsH[0];
			ledsBottom[LEDS_PER_STRIP - i] = colorsH[2];
			ledsLeft[i] = colorsH[4];
			ledsRight[i] = colorsH[6];
		}

		updateDisplay(true);

		if (activeLEDS == 0)
		{
				shuffleColors();
		}
	}

	endTime = millis() + 15000;
	uint8_t hue;
	uint8_t topHue;
	desiredPeriodInSeconds = 2;

	while (millis() < endTime)
	{
		// In the following line, the period for one wave is 255, and millis() / 16 means that there will be ~ 62 ticks per second.
		// This comes out to be a roughly four second period.  Then I need to divide it by (255 / LEDS_PER_STRIP) to get a number that
		// varies between 0 and LEDS_PER_STRIP.
		hue = cubicwave8(millis() / 4 / desiredPeriodInSeconds);
		topHue = cubicwave8(millis() / 4 / desiredPeriodInSeconds) / 10;

		blankDisplay();

		for (int i = 0; i < LEDS_PER_STRIP; i++)
		{
			ledsTop[i] = CHSV(topHue, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			ledsBottom[i] = CHSV(topHue + 90, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			ledsLeft[i] = CHSV(topHue + 160, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			ledsRight[i] = CHSV(topHue + 192, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
		}

		updateDisplay(true);
	}
}

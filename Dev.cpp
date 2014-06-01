// 
// 
// 

#include "Dev.h"

Dev::Dev(CRGB *leds, long duration, int speed, int postDelay) : Pattern::Pattern(leds, duration, speed, postDelay) {}

int idex = 0;
int iHue = 0;

void Dev::draw()
{
	movingPattern();
	colorPalette();
	cubicEasingTest();
}

void Dev::movingPattern()
{
	blankDisplay();

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < LEDS_PER_STRIP; i++)
		{
			ledsTop[i] = hRed;
			updateDisplay(true);
			FastLED.delay(20);

			ledsTop[i] = hBlack;
			updateDisplay(true);
			FastLED.delay(20);
		}
	}

}

void Dev::colorPalette()
{
	const CHSV colorsP[] = {
		hRed,
		hOrange, 
		hGold, 
		hYellow, 
		hGreen, 
		hDarkGreen, 
		hAqua, 
		hSkyBlue, 
		hBlue, 
		hPurple, 
		hMagenta, 
		hPink, 
		hPinkRed, 
		hWhite,
		hGray,
		hGrayDim
	};

	for (int i = 0; i < (sizeof(colorsP) / sizeof(colorsP)[0]); i++)
	{
		fill_solid(m_pLeds, NUM_LEDS, colorsP[i]);
		FastLED.show();
		FastLED.delay(1000);
	}
}

void Dev::cubicEasingTest()
{
	int led_start = 0;
	int led_end   = LEDS_PER_STRIP;
	int led_range = led_end - led_start;
	int pause = 50;

	blankCircleArrays();
	blankDisplay();

	for (int r = 0; r < 8; r++)
	{
		for( int i=0; i< led_range; i++ ) {  // move thru range
			fract8 f = (256 * i) / led_range;  // convert range to "fract8" percentage
			fract8 eased = ease8InOutCubic( f ) ; // get eased version
			int pos = led_start + (eased * led_range)/256;

			ledsLeft[pos] = CHSV(hRed.h + 0, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			ledsTop[pos] = CHSV(hGreen.h + 0, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			ledsRight[pos] = CHSV(hBlue.h + 0, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			ledsBottom[pos] = CHSV(hPurple.h + 0, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);

			updateDisplay(true);
			FastLED.delay(pause);

			ledsLeft[pos] = CRGB::Black;
			ledsTop[pos] = CRGB::Black;
			ledsRight[pos] = CRGB::Black;
			ledsBottom[pos] = hBlack;

			updateDisplay(true);
			CHSV(hRed.h + i, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);		}

		delay(200);
		pause -= 4;
	}
}

void Dev::jasonTest()
{
	unsigned long duration = 40000;
	unsigned long endTime = millis() + duration;

	//	for(int loop = 0; loop < 600; loop++)
	while (millis() < endTime)
	{

		//int x = (sin16(millis() * (65535 / 3000)) / 256) + 128;
		double x = min(max(0,((double)(millis() % 5000) / 1000) - .5),4);
		int intens = (-pow(x - 2,4) + (4 * pow(x - 2,2)) + 1 ) * 51; 
		for (int i = 0; i < NUM_LEDS; i++)
		{
//			leds[i] = CHSV(hYellow.hue,255,intens );
			m_pLeds[i] = CHSV(255,255,intens);
		}
		FastLED.show();
		FastLED.delay(10);

	}
}

void Dev::jasonTestTwo()
{
	unsigned long duration = 148000;
	unsigned long endTime = millis() + duration;

	//	for(int loop = 0; loop < 600; loop++)
	while (millis() < endTime)
	{

		//int x = (sin16(millis() * (65535 / 3000)) / 256) + 128;
		double x = ((double)(millis() % 148000) / 1000) ;
		int intens = (sin(PI * ((x / 8) + .25))* x - (x / 1) * -1) * 16;
		for (int i = 0; i < NUM_LEDS; i++)
		{
//			leds[i] = CHSV(hYellow.hue,255,intens );
			m_pLeds[i] = CHSV(intens,255,255);
		}
		FastLED.show();
		FastLED.delay(10);

	}
}

void Dev::alphaTestPattern()
{
	int lowerIndex;
	int upperIndex;
	uint8_t bgLeft = hGold.hue;
	uint8_t bgTop = hGold.hue;
	uint8_t bgRight = hGold.hue;
	uint8_t bgBottom = hGold.hue;

	blankDisplay();

	for (int k = 0; k < 1000; k++)
	{
		for (int i = 0; i < (LEDS_PER_STRIP / 2); i++)
		{
			//fill_solid(ledsLeft, LEDS_PER_STRIP, CHSV(bgLeft, 255, 100));
			fill_solid(ledsTop, LEDS_PER_STRIP, CHSV(bgTop, 255, 100));
			//fill_solid(ledsRight, LEDS_PER_STRIP, CHSV(bgRight, 255, 100));
			//fill_solid(ledsBottom, LEDS_PER_STRIP, CHSV(bgBottom, 255, 100));

			for (int j = 0; j < 5; j++)
			{
				lowerIndex = i + j;
				upperIndex = i + j + (LEDS_PER_STRIP / 2);
				if (upperIndex >= LEDS_PER_STRIP)
				{
					upperIndex = upperIndex - LEDS_PER_STRIP;
				}

				//ledsLeft[lowerIndex] = hRed;
				//ledsLeft[upperIndex] = hRed;

				ledsTop[lowerIndex] = hBlue;
				ledsTop[upperIndex] = hBlue;

				//ledsRight[lowerIndex] = hGreen;
				//ledsRight[upperIndex] = hGreen;

				//ledsBottom[lowerIndex] = hPurple;
				//ledsBottom[upperIndex] = hPurple;
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

void Dev::propTest()
{

	uint8_t m_Segments = 4;
	uint8_t segmentSize = 9;
	uint8_t hueOffset = 0;

	//for (int i = 0; i < 1000; i++)
	//{
		for (int j = 0; j < m_Segments; j++)
		{
			ledsTop[(idex + (j * segmentSize)) % LEDS_PER_STRIP] = CHSV((j * (255 / m_Segments)) + hueOffset, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
		}

		fill_solid(ledsBottom, LEDS_PER_STRIP, CHSV(iHue % 255, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS));

		idex++;
		iHue++;
//		updateDisplay(true);
//		FastLED.delay(50);
	//}
}

void Dev::fadeTest()
{
	CRGB ledsTEMP[LEDS_PER_STRIP];

	uint8_t r, g, b;
	double dR, dG, dB;
	uint8_t numberOfSteps = 60;
	double j = 0;

	//// Copy the output array to a temp location
	//for (int i = 0; i < LEDS_PER_STRIP; i++)
	//{
	//	ledsTEMP[i] = ledsBottom[i];
	//	ledsLeft[i] = ledsBottom[i];
	//}

	for (int i = 0; i < 200; i++)
	{
		propTest();

		// These two loops cause a dissolve from one circle to the other.
		//for (double j = 0; j <= numberOfSteps; j++)
		//{
		if (j <= numberOfSteps)
		{
			for (int i = 0; i < LEDS_PER_STRIP; i++)
			{
				// These three lines add a portion of each input array and write it to the output array.  The portions
				// move to progressively more and more of the output array during the "i" loop.  This is done purely
				// using color.  If the input arrays where CHSV, I could do this using value instead.
				r = (ledsTop[i].r * ((numberOfSteps - j) / numberOfSteps)) + (ledsBottom[i].r * (j / numberOfSteps));
				g = (ledsTop[i].g * ((numberOfSteps - j) / numberOfSteps)) + (ledsBottom[i].g * (j / numberOfSteps));
				b = (ledsTop[i].b * ((numberOfSteps - j) / numberOfSteps)) + (ledsBottom[i].b * (j / numberOfSteps));

				ledsLeft[i].r = r;
				ledsLeft[i].g = g;
				ledsLeft[i].b = b;
			}

		}

		updateDisplay(true);
		j++;

		if (j == 1)
		{
			FastLED.delay(3000);
		}

		FastLED.delay(6000 / numberOfSteps);
		//}
	}
}

void Dev::movingBlack()
{
	CHSV movingBandColor = CHSV(hGreen.hue, 255, 0);

	uint8_t hue = hPurple.hue;
	uint8_t brightness = 80;
	uint8_t bandWidth = 6;

	for (int i = 0; i < 4; i++)
	{
		shuffleColors();

		for (int i = 0; i < NUM_LEDS - bandWidth; i++)
		{
			for (int b = 0; b < 4; b++)
			{
				fill_rainbow(m_pLeds + (b * LEDS_PER_STRIP), LEDS_PER_STRIP, b * 50, 1);
			}

			//fill_solid(m_pLeds, NUM_LEDS, CHSV(hue, DEFAULT_SATURATION, brightness));
			//fill_rainbow(m_pLeds, LEDS_PER_STRIP, 160, 2);

			for (int b = 0; b < bandWidth; b++)
			{
				m_pLeds[i + b] = movingBandColor;
			}

//			updateDisplay(true);
			FastLED.show();
			FastLED.delay(50);
		}

		hue += 255 / 9;
		FastLED.delay(500);
	}
}

void Dev::oneCycleTest()
{
	double desiredPeriodInSeconds = 2;
	uint8_t hue = hBlue.hue;
	uint8_t brightness;

	blankDisplay();

	//for (int i = 0; i < 512; i++)
	//{
	//	Serial.print("i = ");
	//	Serial.print(i);
	//	Serial.print(", sin8(i) = ");
	//	Serial.print(sin8(i));
	//	Serial.print(", cubicwave8(i) = ");
	//	Serial.print(cubicwave8(i));
	//	Serial.print(", quadwave8(i) = ");
	//	Serial.print(quadwave8(i));
	//	Serial.print(", cos8(i) = ");
	//	Serial.println(cos8(i));
	//}

	int periodInMilliseconds = 3000;

	for (int k = 0; k < 4; k++)
	{
		//for (int i = 0; i < 255; i++)
		//{
		//	for (int j = 0; j < LEDS_PER_STRIP; j++)
		//	{
		//		ledsTop[j] = CHSV(hue, 255, quadwave8(i));
		//		ledsBottom[j] = CHSV(hue + 50, 255, quadwave8(i));
		//		ledsLeft[j] = CHSV(hue + 100, 255, quadwave8(i));
		//		ledsRight[j] = CHSV(hue + 150, 255, quadwave8(i));
		//	}

		//	updateDisplay(true);
		//	FastLED.delay(periodInMilliseconds / 255);
		//}

		//FastLED.delay(1000);

		//for (int i = 0; i < 255; i++)
		//{
		//	for (int j = 0; j < LEDS_PER_STRIP; j++)
		//	{
		//		ledsTop[j] = CHSV(hue, 255, cubicwave8(i));
		//		ledsBottom[j] = CHSV(hue, 255, cubicwave8(i));
		//		ledsLeft[j] = CHSV(hue, 255, cubicwave8(i));
		//		ledsRight[j] = CHSV(hue, 255, cubicwave8(i));
		//	}

		//	updateDisplay(true);
		//	FastLED.delay(periodInMilliseconds / 255);
		//}

		//FastLED.delay(2000);

		for (int i = 0; i < 255; i++)
		{
			brightness = quadwave8(i);

			for (int j = 0; j < LEDS_PER_STRIP; j++)
			{
				ledsTop[j] = CHSV(hue, 255, brightness);
				ledsBottom[j] = CHSV(hue, 255, brightness);
				ledsLeft[j] = CHSV(hue, 255, brightness);
				ledsRight[j] = CHSV(hue, 255, brightness);
			}

			updateDisplay(true);
			FastLED.delay(periodInMilliseconds / 255);
		}

		FastLED.delay(2000);

		//for (int i = 192; i < 192 + 256; i++)
		//{
		//	brightness = sin8(i);
		//	//if (brightness < 5)
		//	//{
		//	//	brightness = 0;
		//	//}

		//	for (int j = 0; j < LEDS_PER_STRIP; j++)
		//	{
		//		ledsTop[j] = CHSV(hue, 255, brightness);
		//		ledsBottom[j] = CHSV(hue, 255, brightness);
		//		ledsLeft[j] = CHSV(hue, 255, brightness);
		//		ledsRight[j] = CHSV(hue, 255, brightness);
		//	}

		//	updateDisplay(true);
		//	FastLED.delay(periodInMilliseconds / 255);
		//}

		//FastLED.delay(2000);

		//for (int i = 128; i < 128 + 255; i++)
		//{
		//	for (int j = 0; j < LEDS_PER_STRIP; j++)
		//	{
		//		ledsTop[j] = CHSV(hue, 255, cos8(i));
		//		ledsBottom[j] = CHSV(hue + 50, 255, cos8(i));
		//		ledsLeft[j] = CHSV(hue + 100, 255, cos8(i));
		//		ledsRight[j] = CHSV(hue + 150, 255, cos8(i));
		//	}

		//	updateDisplay(true);
		//	FastLED.delay(periodInMilliseconds / 255);
		//}

		//hue += 50;
		//FastLED.delay(1000);
	}
}

// Turn complete circles on and off using a math function
void Dev::sineCircles()
{
	long endTime = millis() + 8000;
	double desiredPeriodInSeconds = 2;
	uint8_t activeCircles;

	while (millis() < endTime)
	{
		// In the following line, the period for one wave is 255.  As such, millis() / 16 means that there will be ~ 62 ticks per second.
		// This comes out to be a roughly four second period.  Then I need to divide it by (255 / LEDS_PER_STRIP) to get a number that
		// varies between 0 and LEDS_PER_STRIP.

		activeCircles = triwave8(millis() / 4 / desiredPeriodInSeconds)  / (255 / 5);

		blankDisplay();

		if (activeCircles > 0)
		{
			fill_solid(ledsTop, LEDS_PER_STRIP, colorsH[0]);
		}

		if (activeCircles > 1)
		{
			fill_solid(ledsRight, LEDS_PER_STRIP, colorsH[1]);
		}

		if (activeCircles > 2)
		{
			fill_solid(ledsBottom, LEDS_PER_STRIP,colorsH[2]);
		}

		if (activeCircles > 3)
		{
			fill_solid(ledsLeft, LEDS_PER_STRIP, colorsH[3]);
		}

		updateDisplay(true);

		if (activeCircles == 0)
		{
			shuffleColors();
		}
	}
}

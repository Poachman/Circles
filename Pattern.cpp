// 
// 
// 

#include "Pattern.h"
#include "Constants.h"
#include "FastLED.h"

Pattern::Pattern(CRGB *leds, long duration, int speed, int postDelay) : m_pLeds(leds), m_Duration(duration), m_Speed(speed), m_PostDelay(postDelay) {}

CHSV colorsH[] = {
					hRed,
					hOrange, 
					hGold, 
					hYellow, 
					hGreen, 
//					hDarkGreen, 
					hAqua, 
					hSkyBlue, 
					hBlue, 
					hPurple, 
					hMagenta, 
					hPink, 
					hPinkRed, 
					hWhite,
//					hGray,
//					hGrayDim
};

CRGB ledsLeft[LEDS_PER_STRIP];
CRGB ledsTop[LEDS_PER_STRIP];
CRGB ledsRight[LEDS_PER_STRIP];
CRGB ledsBottom[LEDS_PER_STRIP];

void Pattern::shuffle (CHSV *t, int n)
{
	// from the algorithm found at http://stackoverflow.com/questions/3343797/is-this-c-implementation-of-fisher-yates-shuffle-correct

	for (int i = n - 1; i > 0; i--)
	{
		int k = random (i); // 0 <= k <= n - 1
		// Swap
		CHSV temp = t[k];
		t[k] = t[i];
		t[i] = temp;
	}
}  // end of shuffle

void Pattern::shuffleColors()
{
//	shuffle(colors, sizeof(colors) / sizeof(CRGB));
//	shuffle(colorsH, sizeof(colorsH) / sizeof(CHSV));
	shuffle(colorsH, 13);
	//shuffle(darkColors, sizeof(darkColors) / sizeof(CHSV));
	//shuffle(lightColors, sizeof(lightColors) / sizeof(CHSV));
}

// Copy all of the circle LEDS to the output array, and call FastLED.show()
void Pattern::updateDisplay(bool sendToOutput)
{
	int outputIndex = 0;

	// The physical wiring order of the circles is Top, Left, Botttom, Right.

	for (int i = 0; i < LEDS_PER_STRIP; i++)
	{
		m_pLeds[outputIndex++] = ledsTop[i];
	}

	for (int i = 0; i < LEDS_PER_STRIP; i++)
	{
		m_pLeds[outputIndex++] = ledsLeft[i];
	}

	for (int i = 0; i < LEDS_PER_STRIP; i++)
	{
		m_pLeds[outputIndex++] = ledsBottom[i];
	}

	// The right circle is currently mounted upside down.  As such, it runs in the opposite direction of the other circles.
	// This can easily be fixed though by running the population loop in reverse.
//	for (int i = LEDS_PER_STRIP - 1; i >= 0; i--)
	for (int i = 0; i < LEDS_PER_STRIP; i++)
	{
		m_pLeds[outputIndex++] = ledsRight[i];
	}

	if (sendToOutput == true)
	{
		FastLED.show();
	}
}

void Pattern::blankCircleArrays()
{
	for (int i = 0; i < LEDS_PER_STRIP; i++)
	{
		ledsLeft[i] = hBlack;
		ledsRight[i] = hBlack;
		ledsTop[i] = hBlack;
		ledsBottom[i] = hBlack;
	}
}

void Pattern::blankDisplay()
{
	blankCircleArrays();
	FastLED.clear();
}


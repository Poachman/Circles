// 
// Bananas
// 

#include "Propeller.h"

// Draw an RGB "propeller".  Segments is the desired number of segments / bands (props?)
// A value of 0 for segments will result in a random number between 3 and 6
// A value of 0 for speed will result in a random number between 40 and 100
// Setting blackSpaces to true will cause the segments to be half color, half black
Propeller::Propeller(CRGB *leds, long duration, int speed, int postDelay, uint8_t segments, bool rotationDirection, bool blackSpaces) : Pattern::Pattern(leds, duration, speed, postDelay), m_Segments(segments), m_RotationDirection(rotationDirection), m_BlackSpaces(blackSpaces) {}

void Propeller::draw()
{
	// also add a parameter for the desired circle LED array?
	// if desired, I could also create a const uint8_t array for the various hues (instead of using colorsH)

	if (m_Segments == 0)
	{
		m_Segments = random8(3, 6);
	}

	if (m_Speed == 0)
	{
		m_Speed = random8(40, 100);
	}

	unsigned long endTime = millis() + m_Duration;
	uint idex = 0;													// the starting point for the first pass.  This gets incremented to cause the rotation.

	uint8_t segmentSize = (int)(LEDS_PER_STRIP / m_Segments);		// the starting point in the circle for each new color
	uint8_t hueOffset = 0;											// how much to add to hue for each new segment
	double desiredPeriodInSeconds = 5;								// the period for the sine wave used to vary the color of each segment
	uint8_t m_Segments2 = 6;
	uint8_t segmentSize2 = 6;

	while (millis() < endTime)
	{

		// Change colors (within a small range) over a period of five seconds
		hueOffset = sin8(millis() / 4 / desiredPeriodInSeconds) / m_Segments / 3;			// an integer varying between 0 and (255 / 8)

		// Uncommenting the following line will cause half of each segment to be black LEDs
		if (m_BlackSpaces == true)
		{
			blankDisplay();
		}

		// This loop only has any visible effect if the blankDisplay is uncommented.  In that case, the "segmentSize / 2" code only draws half of each 
		// segment, and the rest is left blank.  If the display is *not* blanked, then this loop is irelevant, as the segments eventually
		// get filled in anyway.
		for(int i = 0; i < segmentSize / 2; i++ )
		{
			// This loop causes four LEDs to be lit, at segmentSize spacing intervals.  After that, idex is incremented and the process is repeated.
			// This eventually causes the sgements to get filled up to the appropriate size.
			for (int j = 0; j < m_Segments; j++)
			{
				ledsTop[(idex + i + (j * segmentSize)) % LEDS_PER_STRIP] = CHSV((j * (255 / m_Segments)) + hueOffset, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
				ledsBottom[(idex + i + (j * segmentSize)) % LEDS_PER_STRIP] = CHSV((j * (255 / m_Segments)) + hueOffset, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			}				//ledsLeft[(idex + i + (j * segmentSize)) % LEDS_PER_STRIP] = CHSV((j * (255 / m_Segments)) + hueOffset, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
				//ledsRight[(idex + i + (j * segmentSize)) % LEDS_PER_STRIP] = CHSV((j * (255 / m_Segments)) + hueOffset, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);

		}

		for(int i = 0; i < segmentSize2 / 2; i++ )
		{
			// This loop causes four LEDs to be lit, at segmentSize spacing intervals.  After that, idex is incremented and the process is repeated.
			// This eventually causes the sgements to get filled up to the appropriate size.
			for (int j = 0; j < m_Segments2; j++)
			{
				//ledsTop[(idex + i + (j * segmentSize)) % LEDS_PER_STRIP] = CHSV((j * (255 / m_Segments)) + hueOffset, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
				//ledsBottom[(idex + i + (j * segmentSize)) % LEDS_PER_STRIP] = CHSV((j * (255 / m_Segments)) + hueOffset, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
				ledsLeft[(idex + i + (j * segmentSize2)) % LEDS_PER_STRIP] = CHSV((j * (255 / m_Segments2)) + hueOffset, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
				ledsRight[(idex + i + (j * segmentSize2)) % LEDS_PER_STRIP] = CHSV((j * (255 / m_Segments2)) + hueOffset, DEFAULT_SATURATION, DEFAULT_BRIGHTNESS);
			}
		}

		if (m_RotationDirection == CLOCKWISE)
		{
			idex++;
		}
		else
		{
			idex--;
		}

		updateDisplay(true);
		FastLED.delay(m_Speed);
	}
}

#include "Propeller.h"
#include "ColorSlide.h"
#include "ColorSlide2.h"
#include "AlphaTest.h"
#include "ProgressiveColorBands.h"
#include "WaveTest.h"
#include "Triplets.h"
#include "Pattern.h"
#include "FastLED.h"
#include "Dev.h"
#include "Constants.h"

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 11
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

Pattern *pPatterns[] = {
	new Propeller(leds, 10000, 0, 1000, 3, CLOCKWISE, true),
	//new Dev(leds, 30000, 30, 1000),
	new ColorSlide(leds, 30000, 30, 1000),
	new ColorSlide2(leds, 30000, 30, 1000),
	new Propeller(leds, 10000, 0, 1000, 6, COUNTER_CLOCKWISE, false),
	new AlphaTest(leds, 30000, 30, 1000),
	new ProgressiveColorBands(leds, 30000, 30, 1000),
	new WaveTest(leds, 30000, 30, 1000),
	new Triplets(leds, 30000, 30, 1000),

	// CURRENTLY DISABLED PATTERNS
	//new AntiAliasTest(leds, 15000, 25, 2000, TRANSITION::RANDOM),
	//new ConcentricCircles(leds, 15000, 200, 2000, TRANSITION::NONE, false, false, true),			// single filled version
	//new DrawBox(leds, 0, 10, 3000, TRANSITION::RANDOM),
	//new Fire2012(leds, 15000, 0, 0, TRANSITION::RANDOM),
	//new InAndOutSquares(leds, 10000, 500, 1000, TRANSITION::RANDOM),
	//new JumpingJacks(leds, 10000, 20, 1000, TRANSITION::NONE),
	//new JumpingJacks2(leds, 10000, 40, 1000, TRANSITION::NONE),
	//new ZoomingSquares(leds, 15000, 40, 2000, TRANSITION::RANDOM, false)
};

const uint8_t numPatterns = sizeof(pPatterns) / sizeof(Pattern*);
uint8_t iPattern[numPatterns];

void setup()
{
	Serial.begin(115200);
//	delay(2000);

	FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, BRG>(leds, NUM_LEDS);
	random16_add_entropy(random());
	//blankDisplay();

	Dev *myDev = new Dev(leds, 15000, 0, 0);

	myDev->oneCycleTest();

	//FastLED.delay(10000);

	for (uint8_t i = 0; i < numPatterns; i++)
	{
		iPattern[i] = i;
	}
}

void loop()
{
	for (int i = 0; i < numPatterns; i++)
	{
		random16_add_entropy(random());
		pPatterns[iPattern[i]]->draw();
	}

////	colorPalette();
////	alphaTest();
//	movingDot();
//	expandFromCenter();
//	colorSlide();
//	rgb_propeller(20000, 100, 3);
//	rgb_propeller(10000);
//	rgb_propeller(10000);
//	rgb_propeller(10000);
//	colorSlide2();
//	rainbowLoop();
//	progressiveColorBands();
//	//sineRamp();
//	waveTest();
//	star();
//	colorChase();
//	cubicEasingTest();
//	triplets();
//	//movingLine();
//	//alternatingStrip();
//	clockIn();
//	clockInOut();
//	FastLED.delay(1000);
//	colorDissolve(15000);
////	jasonTest();
}


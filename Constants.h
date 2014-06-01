// Constants.h

#ifndef _CONSTANTS_h
#define _CONSTANTS_h

#include "FastLED.h"

// How many leds in your strip?
const uint8_t LEDS_PER_STRIP = 36;
const uint8_t NUMBER_OF_STRIPS = 4;
const uint8_t NUM_LEDS = LEDS_PER_STRIP * NUMBER_OF_STRIPS;

const static uint8_t DEFAULT_BRIGHTNESS = 255;
const static uint8_t DEFAULT_SATURATION = 255;
const static uint8_t DEFAULT_SPEED = 0;

const static CHSV hRed = CHSV(0, 255, DEFAULT_BRIGHTNESS);
const static CHSV hOrange = CHSV(10, 255, DEFAULT_BRIGHTNESS);
const static CHSV hGold = CHSV(25, 255, DEFAULT_BRIGHTNESS);
const static CHSV hYellow = CHSV(45, 255, DEFAULT_BRIGHTNESS);
const static CHSV hGreen = CHSV(95, 255, DEFAULT_BRIGHTNESS);
const static CHSV hDarkGreen = CHSV(90, 255, 50);
const static CHSV hAqua = CHSV(120, 255, DEFAULT_BRIGHTNESS);
const static CHSV hSkyBlue = CHSV(140, 255, DEFAULT_BRIGHTNESS);
const static CHSV hBlue = CHSV(160, 255, DEFAULT_BRIGHTNESS);
const static CHSV hPurple = CHSV(180, 255, DEFAULT_BRIGHTNESS);
const static CHSV hMagenta = CHSV(205, 255, DEFAULT_BRIGHTNESS);
const static CHSV hPink = CHSV(230, 255, DEFAULT_BRIGHTNESS);
const static CHSV hPinkRed = CHSV(245, 255, DEFAULT_BRIGHTNESS);
const static CHSV hWhite = CHSV(0, 0, DEFAULT_BRIGHTNESS);
const static CHSV hGray = CHSV(0, 0, 80);
const static CHSV hGrayDim = CHSV(0, 0, 30);
const static CHSV hBlack = CHSV(0, 0, 0);

const uint8_t CLOCKWISE = 0;
const uint8_t COUNTER_CLOCKWISE = 1;

#endif

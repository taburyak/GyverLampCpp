#pragma once
#include <Arduino.h>
#include <FastLED.h>
#include <Adafruit_GFX.h>
#include <FastLED_NeoMatrix.h>

#define myMatrix MyMatrix::Instance()

class MyMatrix : public FastLED_NeoMatrix
{
public:
    static MyMatrix *Instance();
    static void Initialize(uint8_t sizeWidth, uint8_t sizeHeight, uint8_t matrixType =
            NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG);

    void setCurrentLimit(uint32_t maxCurrent);

    void matrixTest();

    void fill(CRGB color, bool shouldShow = false);
    void fillProgress(double progress, CRGB color);
    void setLed(uint8_t x, uint8_t y, CRGB color, bool showuldShow = false);
    void setLed(uint16_t index, CRGB color, bool showuldShow = false);
    void fadeToBlackBy(uint16_t index, uint8_t step);

    uint16_t getPixelNumber(uint8_t x, uint8_t y);

    void drawPixelXY(uint8_t x, uint8_t y, CRGB color);
    void drawLineXY(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, CRGB color);
    void drawLineXY(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint16_t color);

    CRGB getPixColor(uint16_t number);
    CRGB getPixColorXY(uint8_t x, uint8_t y);

    void fillRectXY(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);

protected:
    MyMatrix(CRGB *leds, uint8_t w, uint8_t h, uint8_t matrixType);
};

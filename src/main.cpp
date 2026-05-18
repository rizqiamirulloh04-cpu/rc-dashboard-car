#include <Arduino.h>
#include <Arduino_GFX_Library.h>

#define TFT_MOSI 6
#define TFT_SCLK 7
#define TFT_CS   14
#define TFT_DC   15
#define TFT_RST  21
#define TFT_BL   22

Arduino_DataBus *bus = new Arduino_ESP32SPI(
    TFT_DC,
    TFT_CS,
    TFT_SCLK,
    TFT_MOSI,
    -1
);

Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    TFT_RST,
    0,
    true,
    172,
    320
);

void setup()
{
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    gfx->begin();

    gfx->fillScreen(BLACK);

    gfx->setTextColor(WHITE);
    gfx->setTextSize(2);

    gfx->setCursor(20, 40);
    gfx->println("ESP32-C6");

    gfx->setTextColor(GREEN);
    gfx->setCursor(20, 80);
    gfx->println("DISPLAY OK");

    gfx->fillRect(20, 140, 120, 30, RED);
}

void loop()
{
}
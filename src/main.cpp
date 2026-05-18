#include <Arduino.h>
#include <Arduino_GFX_Library.h>

#define TFT_BL 15

Arduino_DataBus *bus = new Arduino_ESP32SPI(
    6,   // DC
    7,   // CS
    5,   // SCK
    4,   // MOSI
    -1   // MISO
);

Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    21,  // RST
    0,   // rotation
    true,
    172,
    320,
    34,
    0,
    0,
    0
);

void setup()
{
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    gfx->begin();
    gfx->fillScreen(BLACK);

    gfx->setTextColor(WHITE);
    gfx->setTextSize(3);
    gfx->setCursor(20, 40);
    gfx->println("ESP32-C6");

    gfx->setTextColor(GREEN);
    gfx->setTextSize(2);
    gfx->setCursor(20, 100);
    gfx->println("LCD OK");

    gfx->fillRect(20, 150, 200, 30, RED);
}

void loop()
{
}
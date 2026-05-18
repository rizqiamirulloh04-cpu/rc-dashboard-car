#include <Arduino.h>
#include <Arduino_GFX_Library.h>

#define TFT_BL 22

Arduino_DataBus *bus = new Arduino_ESP32SPI(
    15, // DC
    14, // CS
    7,  // SCK
    6,  // MOSI
    -1  // MISO
);

Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    21,
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

    gfx->fillScreen(0x0000);

    gfx->setTextColor(0xFFFF);
    gfx->setTextSize(2);

    gfx->setCursor(20, 40);
    gfx->println("ESP32-C6 OK");

    gfx->fillRect(20, 100, 100, 40, 0xF800);
}

void loop()
{
}
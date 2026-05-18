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
    21,   // RST
    0,    // rotation
    true, // IPS
    172, 320
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
    gfx->println("ESP32-C6 OK");

    gfx->fillRect(20, 100, 100, 40, RED);
}

void loop()
{
}
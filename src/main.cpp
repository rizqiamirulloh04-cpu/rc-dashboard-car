#include <Arduino.h>
#include <Arduino_GFX_Library.h>

Arduino_DataBus *bus = new Arduino_ESP32SPI(
    8,   // DC
    7,   // CS
    6,   // SCK
    10,  // MOSI
    -1
);

Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    3,
    1,
    true,
    172,
    320
);

void setup()
{
    pinMode(22, OUTPUT);
    digitalWrite(22, HIGH);

    gfx->begin();

    gfx->fillScreen(BLACK);

    gfx->setTextColor(GREEN);
    gfx->setTextSize(2);

    gfx->setCursor(30, 40);
    gfx->println("RC DASHBOARD");

    gfx->setCursor(50, 80);
    gfx->println("ESP32-C6");

    gfx->drawRect(20, 140, 280, 30, WHITE);
    gfx->fillRect(20, 140, 180, 30, GREEN);

    gfx->setCursor(90, 190);
    gfx->println("Throttle");
}

void loop()
{
}
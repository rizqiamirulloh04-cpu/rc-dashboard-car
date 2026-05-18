#include <Arduino.h>
#include <Arduino_GFX_Library.h>

#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0

Arduino_DataBus *bus = new Arduino_ESP32SPI(
    8, 7, 6, 10, -1
);

Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    9,
    0,
    true,
    172,
    320
);

void setup()
{
    gfx->begin();
    gfx->fillScreen(BLACK);

    gfx->setCursor(20, 40);
    gfx->setTextColor(WHITE);
    gfx->setTextSize(2);
    gfx->println("RC Dashboard");

    gfx->setCursor(20, 80);
    gfx->setTextColor(GREEN);
    gfx->println("CONNECTED");

    gfx->fillRect(20, 150, 200, 30, RED);
}

void loop()
{
}
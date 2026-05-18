#include <Arduino.h>
#include <Arduino_GFX_Library.h>

#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0
#include <Arduino.h>
#include <Arduino_GFX_Library.h>

Arduino_DataBus *bus = new Arduino_ESP32SPI(
    8,   // DC
    14,  // CS
    7,   // SCK
    6,   // MOSI
    -1   // MISO
);

Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    21,  // RST
    0,   // rotation
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

    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->setCursor(20, 40);
    gfx->println("RC DASH");

    gfx->setTextColor(WHITE);
    gfx->setTextSize(2);
    gfx->setCursor(20, 100);
    gfx->println("ESP32-C6");

    gfx->drawRect(20, 150, 130, 20, WHITE);
    gfx->fillRect(20, 150, 90, 20, GREEN);
}

void loop()
{
}
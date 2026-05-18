#include <Arduino.h>
#include <Arduino_GFX_Library.h>

#define TFT_BL 15

#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0

// SPI bus
Arduino_DataBus *bus = new Arduino_ESP32SPI(
    8,   // DC
    7,   // CS
    6,   // SCK
    10,  // MOSI
    -1   // MISO
);

// ST7789 display
Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    9,      // RST
    0,      // rotation
    true,   // IPS
    172,    // width
    320,    // height
    34,     // col offset
    0,      // row offset
    35,     // col offset 2
    0       // row offset 2
);

void setup()
{
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    gfx->begin();
    gfx->fillScreen(BLACK);

    gfx->setCursor(20, 40);
    gfx->setTextColor(WHITE);
    gfx->setTextSize(2);
    gfx->println("RC Dashboard");

    gfx->setCursor(20, 80);
    gfx->setTextColor(GREEN);
    gfx->println("DISPLAY OK");

    gfx->fillRect(20, 150, 200, 30, RED);
}

void loop()
{
}
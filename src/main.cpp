#include <Arduino.h>
#include <Arduino_GFX_Library.h>

#define TFT_BL 15

// SPI LCD Waveshare ESP32-C6 1.47
Arduino_DataBus *bus = new Arduino_ESP32SPI(
    6,   // DC
    7,   // CS
    10,  // SCK
    11,  // MOSI
    -1   // MISO
);

// ST7789 172x320
Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    14,   // RST
    0,    // rotation
    true,
    172,
    320,
    34,
    0,
    34,
    0
);

void setup()
{
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    gfx->begin();

    // Hitam
    gfx->fillScreen(0x0000);

    // Putih
    gfx->setTextColor(0xFFFF);

    gfx->setTextSize(2);

    gfx->setCursor(20, 40);
    gfx->println("LCD TEST");

    gfx->setTextSize(1);

    gfx->setCursor(20, 80);
    gfx->println("ESP32-C6 WAVESHARE");

    // Merah
    gfx->fillRect(20, 140, 120, 40, 0xF800);

    // Hijau
    gfx->fillRect(20, 200, 120, 40, 0x07E0);

    // Biru
    gfx->fillRect(20, 260, 120, 40, 0x001F);
}

void loop()
{
}
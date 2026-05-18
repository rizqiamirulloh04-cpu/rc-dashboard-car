#include <Arduino.h>
#include <Arduino_GFX_Library.h>

#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0

// =======================
// Waveshare ESP32-C6 LCD 1.47
// =======================

Arduino_DataBus *bus = new Arduino_ESP32SPI(
    4,   // DC
    5,   // CS
    6,   // SCK
    7,   // MOSI
    -1   // MISO
);

Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    15,   // RST
    0,    // rotation
    true,
    172,
    320
);

void setup()
{
    gfx->begin();

    gfx->fillScreen(BLACK);

    // Judul
    gfx->setCursor(40, 30);
    gfx->setTextColor(WHITE);
    gfx->setTextSize(2);
    gfx->println("RC DASHBOARD");

    // Status
    gfx->setCursor(70, 80);
    gfx->setTextColor(GREEN);
    gfx->println("CONNECTED");

    // Bar throttle
    gfx->drawRect(40, 150, 240, 30, WHITE);
    gfx->fillRect(42, 152, 180, 26, RED);

    // Steering text
    gfx->setCursor(100, 220);
    gfx->setTextColor(WHITE);
    gfx->println("STEERING");
}

void loop()
{
}
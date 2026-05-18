#include <Arduino.h>
#include <Arduino_GFX_Library.h>

#define GFX_BL 15

Arduino_DataBus *bus = new Arduino_ESP32SPI(
    6 /* DC */,
    7 /* CS */,
    10 /* SCK */,
    11 /* MOSI */,
    -1 /* MISO */
);

Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    14 /* RST */,
    0 /* rotation */,
    true /* IPS */,
    172,
    320,
    34,
    0,
    34,
    0
);

void setup()
{
    pinMode(GFX_BL, OUTPUT);
    digitalWrite(GFX_BL, HIGH);

    Serial.begin(115200);

    gfx->begin();

    gfx->fillScreen(BLACK);

    gfx->setTextColor(WHITE);
    gfx->setTextSize(2);

    gfx->setCursor(20, 40);
    gfx->println("WAVESHARE");

    gfx->setCursor(20, 80);
    gfx->println("ESP32-C6");

    gfx->fillRect(20, 140, 120, 40, RED);
    gfx->fillRect(20, 200, 120, 40, GREEN);
    gfx->fillRect(20, 260, 120, 40, BLUE);
}

void loop()
{
}
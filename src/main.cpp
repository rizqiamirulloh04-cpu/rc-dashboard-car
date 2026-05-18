#include <Arduino.h>
#include <Arduino_GFX_Library.h>

// =====================
// Waveshare ESP32-C6 LCD 1.47
// =====================

// Backlight
#define TFT_BL 22

// SPI Bus
Arduino_DataBus *bus = new Arduino_ESP32SPI(
    15, // DC
    14, // CS
    7,  // SCK
    6,  // MOSI
    -1  // MISO
);

// ST7789 Display
Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    21,   // RST
    1,    // Rotation
    true, // IPS
    172,  // Width
    320,  // Height
    34,   // Column Offset 1
    0,    // Row Offset 1
    34,   // Column Offset 2
    0     // Row Offset 2
);

void setup()
{
    // Serial Debug
    Serial.begin(115200);
    Serial.println("Starting LCD...");

    // Backlight ON
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    delay(200);

    // Init Display
    gfx->begin();

    // Fill Black
    gfx->fillScreen(0x0000);

    // White Text
    gfx->setTextColor(0xFFFF);
    gfx->setTextSize(2);

    // Title
    gfx->setCursor(20, 40);
    gfx->println("WAVESHARE");

    gfx->setCursor(20, 70);
    gfx->println("ESP32-C6");

    // Green Box
    gfx->fillRect(20, 130, 130, 40, 0x07E0);

    // Red Box
    gfx->fillRect(20, 190, 130, 40, 0xF800);

    // Blue Box
    gfx->fillRect(20, 250, 130, 40, 0x001F);

    Serial.println("LCD OK");
}

void loop()
{
}
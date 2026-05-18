#include <Arduino.h>
#include <TFT_eSPI.h>
#include <lvgl.h>

TFT_eSPI tft = TFT_eSPI();

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[172 * 20];

lv_obj_t *speedLabel;
lv_obj_t *steerBar;
lv_obj_t *throttleBar;
lv_obj_t *batteryBar;

int speedValue = 0;
int steerValue = 50;
int throttleValue = 0;
int batteryValue = 90;

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

void setup_ui()
{
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x0D0D0D), 0);

    lv_obj_t *title = lv_label_create(lv_scr_act());
    lv_label_set_text(title, "RC DASHBOARD");
    lv_obj_set_style_text_color(title, lv_color_hex(0x00FFCC), 0);
    lv_obj_set_style_text_font(title, &lv_font_montserrat_20, 0);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 10);

    speedLabel = lv_label_create(lv_scr_act());
    lv_label_set_text(speedLabel, "0 KM/H");
    lv_obj_set_style_text_color(speedLabel, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_font(speedLabel, &lv_font_montserrat_32, 0);
    lv_obj_align(speedLabel, LV_ALIGN_CENTER, 0, -40);

    throttleBar = lv_bar_create(lv_scr_act());
    lv_obj_set_size(throttleBar, 120, 15);
    lv_obj_align(throttleBar, LV_ALIGN_CENTER, 0, 20);
    lv_bar_set_range(throttleBar, 0, 100);

    lv_obj_t *throttleText = lv_label_create(lv_scr_act());
    lv_label_set_text(throttleText, "THROTTLE");
    lv_obj_align_to(throttleText, throttleBar, LV_ALIGN_OUT_TOP_MID, 0, -5);

    steerBar = lv_bar_create(lv_scr_act());
    lv_obj_set_size(steerBar, 120, 15);
    lv_obj_align(steerBar, LV_ALIGN_CENTER, 0, 70);
    lv_bar_set_range(steerBar, 0, 100);

    lv_obj_t *steerText = lv_label_create(lv_scr_act());
    lv_label_set_text(steerText, "STEERING");
    lv_obj_align_to(steerText, steerBar, LV_ALIGN_OUT_TOP_MID, 0, -5);

    batteryBar = lv_bar_create(lv_scr_act());
    lv_obj_set_size(batteryBar, 100, 10);
    lv_obj_align(batteryBar, LV_ALIGN_BOTTOM_MID, 0, -20);
    lv_bar_set_range(batteryBar, 0, 100);
    lv_bar_set_value(batteryBar, batteryValue, LV_ANIM_OFF);

    lv_obj_t *batteryText = lv_label_create(lv_scr_act());
    lv_label_set_text(batteryText, "BATTERY");
    lv_obj_align_to(batteryText, batteryBar, LV_ALIGN_OUT_TOP_MID, 0, -5);
}

void setup()
{
    Serial.begin(115200);

    pinMode(22, OUTPUT);
    digitalWrite(22, HIGH);

    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    lv_init();

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, 172 * 20);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    disp_drv.hor_res = 320;
    disp_drv.ver_res = 172;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;

    lv_disp_drv_register(&disp_drv);

    setup_ui();
}

void loop()
{
    speedValue++;

    if (speedValue > 120)
        speedValue = 0;

    throttleValue = speedValue % 100;
    steerValue = random(20, 80);

    String speedText = String(speedValue) + " KM/H";
    lv_label_set_text(speedLabel, speedText.c_str());

    lv_bar_set_value(throttleBar, throttleValue, LV_ANIM_ON);
    lv_bar_set_value(steerBar, steerValue, LV_ANIM_ON);

    lv_timer_handler();
    delay(30);
}
#include "neo_blinky.h"
#include "global.h"

void neo_blinky(void *pvParameters){

    Adafruit_NeoPixel strip(LED_COUNT, NEO_PIN, NEO_GRB + NEO_KHZ800);
    strip.begin();
    strip.clear();
    strip.show();

    while(1) {
        uint8_t r = 0, g = 0, b = 0;
        
        if (glob_humidity < 40.0) {
            r = 255; g = 120; b = 0;
        }
        else if (glob_humidity < 70.0) {
            r = 0;   g = 255; b = 0; 
        }
        else {
            r = 255; g = 0;   b = 0;
        }

        strip.setPixelColor(0, strip.Color(r, g, b));
        strip.show();
        vTaskDelay(500);

        strip.setPixelColor(0, strip.Color(0, 0, 0));
        strip.show();
        vTaskDelay(500);
    }
}

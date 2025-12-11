#include "led_blinky.h"
#include "global.h"

void led_blinky(void *pvParameters) {
  pinMode(LED_GPIO, OUTPUT);

  while (1) {
    if (xSemaphoreTake(xSemaphoreLed, portMAX_DELAY) == pdPASS)
    {
      if (xQueueReceive(xQueueData, &data, 0) != pdPASS)
      {
        int delay_ms;
    
        if (glob_temperature < 25.0) {
          delay_ms = 1500;      
        }
        else if (glob_temperature < 30.0) {
          delay_ms = 700;
        }
        else {
          delay_ms = 200;
        }
        digitalWrite(LED_GPIO, HIGH);
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);

        digitalWrite(LED_GPIO, LOW);
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);
      }
    }

    
  }
}

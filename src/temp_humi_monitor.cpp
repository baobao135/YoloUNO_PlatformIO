#include "temp_humi_monitor.h"
DHT20 dht20;
LiquidCrystal_I2C lcd(33,16,2);

void temp_humi_monitor(void *pvParameters){

    Wire.begin(11, 12);
    Serial.begin(115200);
    dht20.begin();

    lcd.begin();
    lcd.backlight();
    lcd.clear();    

    while (1){
        
        dht20.read();
        float temperature = dht20.getTemperature();
        float humidity    = dht20.getHumidity();

        if (isnan(temperature) || isnan(humidity)) {
            Serial.println("Failed to read from DHT sensor!");
            temperature = humidity = -1;
        }

        glob_temperature = temperature;
        glob_humidity    = humidity;

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temperature, 1);
        lcd.print(" C");

        lcd.setCursor(0, 1);
        lcd.print("Humi: ");
        lcd.print(humidity, 1);
        lcd.print(" %");

        vTaskDelay(5000);
    }
}

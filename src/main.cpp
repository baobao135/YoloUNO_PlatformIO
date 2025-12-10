#include <Arduino.h>
#include <DHT20.h>


void TaskLEDControl(void *pvParameters) {
  pinMode(GPIO_NUM_48, OUTPUT);

  bool pattern = false;

  while (1) {

    if (!pattern) {
      digitalWrite(GPIO_NUM_48, HIGH);
      vTaskDelay(pdMS_TO_TICKS(1000));

      digitalWrite(GPIO_NUM_48, LOW);
      vTaskDelay(pdMS_TO_TICKS(3000));
    } 
    else {
      digitalWrite(GPIO_NUM_48, HIGH);
      vTaskDelay(pdMS_TO_TICKS(3000));

      digitalWrite(GPIO_NUM_48, LOW);
      vTaskDelay(pdMS_TO_TICKS(1000));
    }
    pattern = !pattern;
  }
}

void TaskTemperature_Humidity(void *pvParameters){
  DHT20 dht20;
  Wire.begin(GPIO_NUM_11, GPIO_NUM_12);
  dht20.begin();
  while(1){
    dht20.read();
    double temperature = dht20.getTemperature();
    double humidity = dht20.getHumidity();

    Serial.print("Temp: "); Serial.print(temperature); Serial.print(" *C ");
    Serial.print(" Humidity: "); Serial.print(humidity); Serial.print(" %");
    Serial.println();
    
    vTaskDelay(5000);
  }

}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  xTaskCreate(TaskLEDControl, "LED Control", 2048, NULL, 2, NULL);
  xTaskCreate(TaskTemperature_Humidity, "LED Control", 2048, NULL, 2, NULL);
  
}

void loop() {
  
}
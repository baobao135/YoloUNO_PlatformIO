#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

extern float glob_temperature;
extern float glob_humidity;

typedef struct
{
    float temperature;
    float humidity;
} Data_Dht20;

extern Data_Dht20 data;

extern String ssid;
extern String password;
extern String wifi_ssid;
extern String wifi_password;
extern boolean isWifiConnected;


extern boolean isWifiConnected;
extern SemaphoreHandle_t xBinarySemaphoreInternet;
extern SemaphoreHandle_t xSemaphoreLed;
extern SemaphoreHandle_t xSemaphoreNeo;
extern QueueHandle_t xQueueData;

#endif
#include "global.h"
float glob_temperature = 0;
float glob_humidity = 0;

Data_Dht20 data = {0, 0};

String ssid = "ESP32-YOUR NETWORK HERE!!!";
String password = "12345678";
String wifi_ssid = "ACLAB";
String wifi_password = "ACLAB2023";
boolean isWifiConnected = false;

SemaphoreHandle_t xBinarySemaphoreInternet = xSemaphoreCreateBinary();
SemaphoreHandle_t xSemaphoreLed =   xSemaphoreCreateBinary();
SemaphoreHandle_t xSemaphoreNeo =   xSemaphoreCreateBinary();
QueueHandle_t xQueueData    =   xQueueCreate(5, sizeof(Data_Dht20));
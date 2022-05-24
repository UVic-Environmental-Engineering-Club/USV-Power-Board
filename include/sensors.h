#ifndef SENSORS
#define SENSORS

#include "rtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/i2c.h>
#include <math.h>
#include "sdkconfig.h"
#include "i2c.h"

#define PIN_SDA 21
#define PIN_CLK 22
#define I2C_ADDRESS 0x1e
#undef ESP_ERROR_CHECK
#define ESP_ERROR_CHECK(x)   do { esp_err_t rc = (x); if (rc != ESP_OK) { ESP_LOGE("err", "esp_err_t = %d", rc); assert(0 && #x);} } while(0);


#endif
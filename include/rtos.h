#ifndef RTOS
#define RTOS

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "communications.h"
#include "sensors.h"
#include "Status_LED.h"

#define UART_TASK_RUN_PERIOD 50
#define I2C_TASK_RUN_PERIOD 50
#define ADC_TASK_RUN_PERIOD 50
#define LED_TASK_RUN_PERIOD 1000

extern xTaskHandle UART_task;
extern xTaskHandle I2C_task;
extern xTaskHandle ADC_task;
extern xTaskHandle LED_task;

void RTOSInit(void);


/**
 * CORE 1 TASKS
 */
void UART_PRIVATETASK(void* params);
void I2C_PRIVATETASK(void* params);
void ADC_PRIVATETASK(void* params);

/**
 * CORE 0 TASKS
 */
void LED_PRIVATETASK(void* params);

#endif
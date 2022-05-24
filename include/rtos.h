#ifndef RTOS
#define RTOS

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "communications.h"
#include "sensors.h"

#define UART_TASK_RUN_PERIOD 50
#define I2C_TASK_RUN_PERIOD 50

extern xTaskHandle UART_task;
extern xTaskHandle I2C_task;

void RTOSInit(void);


/**
 * CORE 1 TASKS
 */
void UART_PRIVATETASK(void* params);
void I2C_PRIVATETASK(void* params);

/**
 * CORE 0 TASKS
 */


#endif
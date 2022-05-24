#include "rtos.h"
#include "sensors.h"

xTaskHandle UART_task;
xTaskHandle I2C_task;
xTaskHandle motorControl_task;
xTaskHandle GPS_task;
xTaskHandle accelerometer_task;
xTaskHandle compass_task;
xTaskHandle lidar_task;



void RTOSInit(void)
{
    xTaskCreatePinnedToCore(UART_PRIVATETASK, "UART", 10000, NULL, 1, &UART_task, 1);
    xTaskCreatePinnedToCore(I2C_PRIVATETASK, "I2C", 10000, NULL, 1, &I2C_task, 1);
}

void UART_PRIVATETASK(void* params)
{
    TickType_t lastRunTime;
    TickType_t runPeriod = UART_TASK_RUN_PERIOD / portTICK_PERIOD_MS;

    lastRunTime = xTaskGetTickCount();

    while(1)
    {
        vTaskDelayUntil(&lastRunTime, runPeriod);
        UART_run();
    }
}

void I2C_PRIVATETASK(void* params)
{
    TickType_t lastRunTime;
    TickType_t runPeriod = I2C_TASK_RUN_PERIOD / portTICK_PERIOD_MS;

    lastRunTime = xTaskGetTickCount();

    while(1)
    {
        vTaskDelayUntil(&lastRunTime, runPeriod);
        I2C_run();
    }
}
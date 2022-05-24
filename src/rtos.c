#include "rtos.h"
#include "sensors.h"

xTaskHandle UART_task;
xTaskHandle I2C_task;
xTaskHandle ADC_task;
xTaskHandle LED_task;




void RTOSInit(void)
{
    /*core 1*/
    xTaskCreatePinnedToCore(UART_PRIVATETASK, "UART", 10000, NULL, 1, &UART_task, 1);
    xTaskCreatePinnedToCore(I2C_PRIVATETASK, "I2C", 10000, NULL, 1, &I2C_task, 1);
    xTaskCreatePinnedToCore(ADC_PRIVATETASK, "ADC", 10000, NULL, 1, &ADC_task, 1);

    /*core 0*/
    xTaskCreatePinnedToCore(LED_PRIVATETASK, "LED", 10000, NULL, 1, &LED_task, 0);

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

void ADC_PRIVATETASK(void* params)
{
    TickType_t lastRunTime;
    TickType_t runPeriod = ADC_TASK_RUN_PERIOD / portTICK_PERIOD_MS;

    lastRunTime = xTaskGetTickCount();

    while(1)
    {
        vTaskDelayUntil(&lastRunTime, runPeriod);
        ADC_run();
    }
}

void LED_PRIVATETASK(void* params)
{
    TickType_t lastRunTime;
    TickType_t runPeriod = LED_TASK_RUN_PERIOD / portTICK_PERIOD_MS;

    lastRunTime = xTaskGetTickCount();

    while(1)
    {
        vTaskDelayUntil(&lastRunTime, runPeriod);
        LED_run();
    }
}
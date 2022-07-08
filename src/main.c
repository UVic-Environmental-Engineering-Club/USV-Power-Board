#include "main.h"


void app_main() 
{
i2c_init();

Status_LED_control_init();

RTOSInit();

}
#include "sensors.h"
#include "config.h"
#include "main.h"
#include "rtos.h"

//Function that describes what program will do when the GPS info is updated by the module
/**
 * @brief GPS Event Handler
 *
 * @param event_handler_arg handler specific arguments
 * @param event_base event base, here is fixed to ESP_NMEA_EVENT
 * @param event_id event id
 * @param event_data event specific arguments
 */
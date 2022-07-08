#include "communications.h"

void UART_run()
{
    
}

void I2C_run()
{
    
}

void LED_run()
{  
  //once we have some global variables set up (like battery life, cell service etc) we can write the logic that will change these colours depending on those variables. 
  //For now, this is the full framework for getting the leds to work. To change led n's colur, just set the new_state.leds[n] to a new colour, then call Status_LED_write(new_state); colours are saved in the header file.
  struct led_state new_state;
  new_state.leds[0] = RED;
  new_state.leds[1] = YELLOW;
  new_state.leds[2] = GREEN;

  Status_LED_write(new_state);
}
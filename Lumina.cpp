// Lumina controller CPP
// 2021
// version 1

#include "Lumina.h"

/* increments mode variable, changing
 * the mode in which the LEDs display.
 */
void advanceMode()
{
    if(mode < MAX_MODE)     // if mode reaches the end, reset the mode
    {
        mode++;
    }
    else
    {
        mode = 0;
    }
}

/* increments mode variable, changing
 * the mode in which the LEDs display.
 */
void decrementMode()
{
    if(mode >= 0)    // if mode reaches the beginning, set it back to the max.
    {
        mode--;
    }
    else
    {
        mode = MAX_MODE;
    }
}

/* sets the mode of the lights by referencing the list
 *  of modes for the LEDs.
 */
void setMode()
{
    FastLED.setTemperature(UncorrectedTemperature); 
    for (int i = 0; i < NUM_LEDS; i++) 
        leds[i] = LED_colors[mode];
}

/* returns the current mode 
   that the LEDs are set to
 */
int getMode()
{
    return mode;
}

/* stores the current mode/brightness of the LEDs
   in EEPROM in order to keep mode memory
 */
void storeMode()
{
    EEPROM.write(1, mode);
    EEPROM.write(2, brightness);
    EEHoldWrite = false;
}


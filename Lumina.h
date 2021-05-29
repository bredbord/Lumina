// Lumina controller
// 2021
// version 1

#ifndef LUMINA_H
#define LUMINA_H

#include <Arduino.h>
#include <FastLED.h>
#include "EEPROM.h"

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define MAX_MODE 11

class Lumina {
    private:
        int mode, brightness;
        bool dimmerDirection, EEHoldWrite;

        CFastLED* FastLEDPtr;

        // functions
        void checkMaxMode();

public:
    Lumina();
    Lumina(CFastLED* ptr);
    ~Lumina();

    void advanceMode();  // increment mode
    void decrementMode();

    void setMode(int val);
    void storeMode();

    int getMode();

};

#endif
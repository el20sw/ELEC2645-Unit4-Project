/* Indicator LED class
*   Interfaces with indicator leds as bus
*/

#ifndef INDICATOR_LED_H
#define INDICATOR_LED_H

#include "mbed.h"

class IndicatorLED {
    public:
        //constructor
        IndicatorLED(PinName ledRed, PinName ledGreen);
        IndicatorLED();

        //destructor
        ~IndicatorLED();

        //low power ticker object for periodic flashing
        LowPowerTicker _ledFlasher;

        //methods
        //intialise LEDs
        void InitLED();
        //indicate locked
        void IndicateLocked();
        //indicate unlocked
        void IndicateUnlocked();
        //indicate alarm
        void IndicateAlarm();
        //method to flash locked
        void FlashLocked();
        //method to flash unlocked
        void FlashUnlocked();

    private:
        //leds as digital objects
        DigitalOut *_lockedLED;
        DigitalOut *_unlockedLED;

        

        
};

#endif
/* Indicator LED class
*  Interfaces with indicator leds
*/

#ifndef INDICATOR_LED_H
#define INDICATOR_LED_H

#include "mbed.h"

#define BLINK_INTERVAL  2s

class IndicatorLED {
    public:
    //Constructor
        IndicatorLED(PinName ledRed, PinName ledGreen);
        IndicatorLED();

    //Destructor
        ~IndicatorLED();

    //Methods
        //change flag - ISR
        void ledFlagChange_ISR() { _ledIndicator_flag = 1; }
        //take the state as an input and attach to the relavent led
        void TickLED(int state);


    private:
    //Objects
        //leds as digital objects
        DigitalOut *_lockedLED;
        DigitalOut *_unlockedLED;
        //Ticker object for periodic flashing
        Ticker *_ledFlasher;

    //Methods
        //intialise LEDs
        void InitLED();
        //attach class object to ticker
        void AttachTicker();
        //detach led from ticker
        void DetachTicker();
        //blink given led
        void Blink(DigitalOut *led);
        //flash locked (red) led
        void FlashLockedLED();
        //flash unlocked (green) led
        void FlashUnlockedLED();

    //Variables
        volatile int _ledIndicator_flag = 0;
  
};

#endif

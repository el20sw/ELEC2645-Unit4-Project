#include "IndicatorLED.h"

IndicatorLED::IndicatorLED(PinName ledRed, PinName ledGreen) : _ledFlasher(){
    _lockedLED = new DigitalOut(ledRed);
    _unlockedLED = new DigitalOut(ledGreen);
    InitLED();
}

void IndicatorLED::InitLED() {
    _lockedLED -> write(0);
    _unlockedLED -> write(0);
}

void IndicatorLED::FlashLocked() {
    _lockedLED -> write(1);
    ThisThread::sleep_for(500ms);
    _lockedLED -> write(0);
}

/*
void IndicatorLED::IndicateLocked() {
    _ledFlasher.attach(&IndicatorLED::FlashLocked, 2.0s);
}
*/

void IndicatorLED::FlashUnlocked() {
    _unlockedLED -> write(1);
    ThisThread::sleep_for(500ms);
    _unlockedLED -> write(0);
}

/*
void IndicatorLED::IndicateLocked() {
    _ledFlasher.attach(&IndicatorLED::FlashLocked, 2);
}
*/

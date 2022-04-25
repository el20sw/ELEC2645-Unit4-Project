#include "IndicatorLED.h"

IndicatorLED::IndicatorLED(PinName ledGreen, PinName ledRed){
    _unlockedLED = new DigitalOut(ledGreen);
    _lockedLED = new DigitalOut(ledRed);
    _ledFlasher = new Ticker();
    InitLED();
    AttachTicker();
}

void IndicatorLED::InitLED() {
    _lockedLED->write(0);
    _unlockedLED->write(0);
}

void IndicatorLED::AttachTicker() {
    _ledFlasher->attach(callback(this, &IndicatorLED::ledFlagChange_ISR), 3s);
}

void IndicatorLED::DetachTicker() {
    _ledFlasher->detach();
}

void IndicatorLED::Blink(DigitalOut *led) {
    //blink led
    led->write(1);
    ThisThread::sleep_for(500ms);
    led->write(0);
}

void IndicatorLED::FlashLockedLED() {
    //On flag change blink led
    if (_ledIndicator_flag) {
        //set led indicator flag to zero
        _ledIndicator_flag = 0;
        //blink led
        Blink(_lockedLED); 
    }
}

void IndicatorLED::FlashUnlockedLED() {
    //On flag change blink led
    if (_ledIndicator_flag) {
        //set led indicator flag to zero
        _ledIndicator_flag = 0;
        //blink led
        Blink(_unlockedLED);
    }
}

void IndicatorLED::TickLED(int state) {
    if (state) FlashUnlockedLED();
    else FlashLockedLED();
}

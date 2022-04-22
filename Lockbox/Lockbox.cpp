#include "Lockbox.h"
#include <cstdio>

// **********************************************************************
//Constructor
Lockbox::Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin) 
    : force_sensor(fsrPin), alarm(buzzerPin), temp_sensor(tmpPin) /*, state_ticker()*/ {
        //Create Screen Controller and initialise
        screen = new ScreenController();
        screen->customInit();
        //Create Access Manager and initialise
        access_manager = new AccessManager(screen);
        AccessManagerInit();
        //Create LockUnlock object for interupt
        lock_button = new LockUnlock(PC_10);
}

// **********************************************************************
// Access Manager Related Methods
void Lockbox::AccessManagerInit() {
    access_manager->SetPasscode();
    _state = 0;
    screen->dispLocked();
}

void Lockbox::LockboxLockUnlock() {
    if (lock_button->getISRflag()) {
        //set flag back to zero
        lock_button->setISRflag(0);

        if (_state) {
            //Lock the lockbox and display locked on lcd
            _state = 0;
            screen->clearLCD();
            ThisThread::sleep_for(100ms);
            screen->dispLocked();
        } else {
            //Begin unlock procedure and then display unlocked on lcd
            LockboxStateChange();
        }
    }
}

void Lockbox::LockboxStateChange() {
    auto dummy = access_manager->EnterPasscode();
    bool PasscodeState = (dummy);
    ThisThread::sleep_for(2s);
    screen->clearLCD();

    if (PasscodeState) {
        _state = 1;
        ThisThread::sleep_for(100ms);
        screen->dispUnlocked();
    } else {
        _state = 0;
        ThisThread::sleep_for(100ms);
        screen -> dispLocked();
    }
}

int Lockbox::GetState() {
    return _state;
}

// **********************************************************************
// Force Sensor Related Methods
void Lockbox::PlayForceAlarm() {
    force_sensor.ReadFSR();
    force_sensor.PrintForceValue();

    if (force_sensor.GetForceValue() > 0.6) {
        //turn on buzzer and display alert message
        screen->dispAlert();
        alarm.PlayNote(NOTE_C5);
    } else {
        //turn off buzzer and clear screen
        alarm.SetPulse_us(0);
        screen->clearLCD();
    }
    
    ThisThread::sleep_for(100ms);  
}

// **********************************************************************
//Debugging Methods
void Lockbox::PrintState(int state) {
    switch (state) {
        case 0:
            printf("\nLocked");
        case 1:
            printf("\nUnlocked");
    }
}

void Lockbox::ShowPasscode() {
    access_manager->PrintPasscode();
}
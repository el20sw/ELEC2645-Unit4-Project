#include "Lockbox.h"
#include <cstdio>

//Constructor
Lockbox::Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin) 
    : force_sensor(fsrPin), alarm(buzzerPin), temp_sensor(tmpPin) /*, state_ticker()*/ {
        //Create Screen Controller and initialise
        screen = new ScreenController();
        screen -> customInit();

        //Create Access Manager and initialise
        access_manager = new AccessManager(screen);
        AccessManagerInit();

        //Create LockUnlock object for interupt
        lock_button = new LockUnlock(PC_10);
}

// **********************************************************************
// Access Manager Related Methods
void Lockbox::AccessManagerInit() {
    access_manager -> SetPasscode();
    _state = 0;
    screen -> dispLocked();
}

void Lockbox::LockboxLockUnlock() {
    if (lock_button -> getISRflag()) {
        //set flag back to zero
        lock_button -> setISRflag(0);

        if (_state) {
            //Lock the lockbox and display locked on lcd
            _state = 0;
            screen -> clearLCD();
            ThisThread::sleep_for(100ms);
            screen -> dispLocked();
        } else {
            //Begin unlock procedure and then display unlocked on lcd
            if (LockboxStateChange()) {
                ThisThread::sleep_for(100ms);
                screen -> dispUnlocked();
            } else {
                ThisThread::sleep_for(100ms);
                screen -> dispLocked();
            }
        }
    }
}

bool Lockbox::LockboxStateChange() {
    bool PasscodeState = access_manager -> EnterPasscode();
    ThisThread::sleep_for(2s);
    screen -> clearLCD();

    if (PasscodeState) {
        _state = 1;
        return true;
    } else {
        _state = 0;
        return false;
    }
}

int Lockbox::GetState() {
    return _state;
}

/*
void Lockbox::StateTickerISR() {
    if(_state != old_state) {
        g_change_state_flag = 1;
        old_state = _state;
    }
}

void Lockbox::DisplayState() {
    state_ticker.attach(&Lockbox::StateTickerISR, 1s);

    if (g_change_state_flag) {
        g_change_state_flag = 0;

        switch (_state) {
            case 0:
                screen -> clearLCD();
                ThisThread::sleep_for(100ms);
                screen -> dispLocked();
            case 1:
                screen -> clearLCD();
                ThisThread::sleep_for(100ms);
                screen -> dispUnlocked();
            
        }
    }
}
*/

void Lockbox::DisplayState() {
    //if state=1 then unlocked else state=0 therefore locked
    switch (_state) {
        case 0:
            screen -> clearLCD();
            ThisThread::sleep_for(100ms);
            screen -> dispLocked();
        case 1:
            screen -> clearLCD();
            ThisThread::sleep_for(100ms);
            screen -> dispUnlocked();
    }
}

// **********************************************************************
// Lock Unlock Interrupt Methods
void Lockbox::LockUnlockISR(volatile int state) {
    
}

// **********************************************************************
// Force Sensor Related Methods
void Lockbox::PlayForceAlarm() {
    force_sensor.ReadFSR();
    force_sensor.PrintForceValue();

    if (force_sensor.GetForceValue() > 0.6) {
        //turn on buzzer and display alert message
        screen -> dispAlert();
        alarm.PlayNote(NOTE_C5);
    } else {
        //turn off buzzer and clear screen
        alarm.SetPulse_us(0);
        screen -> clearLCD();
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
    access_manager -> PrintPasscode();
}
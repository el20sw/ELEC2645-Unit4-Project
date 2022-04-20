#include "Lockbox.h"
#include <cstdio>

//Constructor
Lockbox::Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin) 
    : force_sensor(fsrPin), alarm(buzzerPin), temp_sensor(tmpPin) /*, state_ticker()*/ {
        //Create Screen Controller and initialise
        screen = new ScreenController();
        screen -> customInit();

        //Create Access Manager and initialise
        access_manager = new AccessManager();
        access_manager -> SetPasscode();
        //access_manager = new AccessManager();
        access_manager = new AccessManager(screen, state_ptr);
        AccessManagerInit();
}

// **********************************************************************
// Access Manager Related Methods
void Lockbox::AccessManagerInit() {
    access_manager -> SetPasscode();
    _state = 0;
}

void Lockbox::LockboxStateChange() {
    if (access_manager -> EnterPasscode()) _state = 1;
    ThisThread::sleep_for(1s);
    screen -> clearLCD();
}

void Lockbox::ShowPasscode() {
    access_manager -> PrintPasscode();
}

void Lockbox::PrintState(int state) {
    switch (state) {
        case 0:
            printf("\nLocked");
        case 1:
            printf("\nUnlocked");
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

// **********************************************************************
// Force Sensor Related Methods
void Lockbox::PlayForceAlarm(){
    
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


void Lockbox::ShowPasscode() {
    access_manager -> PrintPasscode();
}
#include "Lockbox.h"

Lockbox::Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin) 
    : force_sensor(fsrPin), alarm(buzzerPin), temp_sensor(tmpPin) {
        //Create Screen Controller and initialise
        screen = new ScreenController();
        screen -> customInit();

        //Create Access Manager and initialise
        //access_manager = new AccessManager();
        //access_manager -> SetPasscode();
    }

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

/*
void Lockbox::ShowPasscode() {
    access_manager -> PrintPasscode();
}
*/
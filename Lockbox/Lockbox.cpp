#include "Lockbox.h"

Lockbox::Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin) 
    : ForceSensor(fsrPin), Alarm(buzzerPin), TempSensor(tmpPin) {
        lcd_control = new LCD_Controller();
        lcd_control -> customInit();
    }

void Lockbox::PlayForceAlarm(){
    float val;
        ReadFSR();
        PrintForceValue();
        val = GetForceValue();
        if (val > 0.6) {
            lcd_control -> dispAlert();
            PlayNote(NOTE_C5);
        } else {
            //turn off buzzer
            SetPulse_us(0);
            lcd_control -> clearLCD();
        }
        
        ThisThread::sleep_for(100ms);
        
}
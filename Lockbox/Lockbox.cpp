#include "Lockbox.h"

Lockbox::Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin) 
    : force_sensor(fsrPin), alarm(buzzerPin), temp_sensor(tmpPin) {
        lcd_control = new ScreenController();
        lcd_control -> customInit();
    }

void Lockbox::PlayForceAlarm(){
    
    force_sensor.ReadFSR();
    force_sensor.PrintForceValue();
    float val = force_sensor.GetForceValue();
    if (val > 0.6) {
        lcd_control -> dispAlert();
        alarm.PlayNote(NOTE_C5);
    } else {
        //turn off buzzer
        alarm.SetPulse_us(0);
        lcd_control -> clearLCD();
    }
    
    ThisThread::sleep_for(100ms);
        
}
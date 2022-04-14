#include "Lockbox.h"

Lockbox::Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin) 
    : FSR_Sensor(fsrPin), Alarm(buzzerPin), Temp_Sensor(tmpPin) {
        lcd_control = new LCD_Controller();
        lcd_control -> customInit();
    }

void Lockbox::fsr_alarm(){
    float val;
        set_FSR();
        print_FSR();
        val = get_FSR();
        if (val > 0.6) {
            lcd_control -> dispAlert();
            play_note(NOTE_C5);
        } else {
            //turn off buzzer
            setpulse_us(0);
            lcd_control -> clearLCD();
        }
        
        ThisThread::sleep_for(100ms);
        
}
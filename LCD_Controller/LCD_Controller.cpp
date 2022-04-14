#include "LCD_Controller.h"

LCD_Controller::LCD_Controller() {
    lcd = new N5110(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
}

void LCD_Controller:: lcdOff(){
    lcd -> turnOff();
}

void LCD_Controller::customInit() {
    lcd -> init(LPH7366_1);        //initialise for LPH7366-1 LCD (Options are LPH7366_1 and LPH7366_6)
    lcd -> setContrast(0.55);      //set contrast to 55%
    lcd -> setBrightness(0.5);     //set brightness to 50% (utilises the PWM)
    lcd -> clear();
}

void LCD_Controller::clearLCD() {
    lcd -> clear();
    lcd -> refresh();
}

void LCD_Controller::dispAlert() {
        lcd -> printString(" Alert ", 4, 1);
        lcd -> refresh();
        //ThisThread::sleep_for(2s);
}
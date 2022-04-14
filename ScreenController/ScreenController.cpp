#include "ScreenController.h"

ScreenController::ScreenController() {
    lcd = new N5110(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
}

void ScreenController:: ScreenOff(){
    lcd -> turnOff();
}

void ScreenController::customInit() {
    lcd -> init(LPH7366_1);        //initialise for LPH7366-1 LCD (Options are LPH7366_1 and LPH7366_6)
    lcd -> setContrast(0.55);      //set contrast to 55%
    lcd -> setBrightness(0.5);     //set brightness to 50% (utilises the PWM)
    lcd -> clear();
}

void ScreenController::clearLCD() {
    lcd -> clear();
    lcd -> refresh();
}

void ScreenController::dispAlert() {
    lcd -> printString(" Alert ", 20, 2);
    lcd -> refresh();
    //ThisThread::sleep_for(2s);
}

void ScreenController::dispLocked() {
    lcd -> printString(" Locked ", 5, 3);
    lcd -> refresh();
}
#include "ScreenController.h"

ScreenController::ScreenController() {
    _lcd = new N5110(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
}

/*
ScreenController::~ScreenController() {
    delete _lcd;
}
*/

void ScreenController:: ScreenOff(){
    _lcd -> turnOff();
}

void ScreenController::customInit() {
    _lcd -> init(LPH7366_1);        //initialise for LPH7366-1 _lcd (Options are LPH7366_1 and LPH7366_6)
    _lcd -> setContrast(0.55);      //set contrast to 55%
    _lcd -> setBrightness(0.5);     //set brightness to 50% (utilises the PWM)
    _lcd -> clear();
}

void ScreenController::clearLCD() {
    _lcd -> clear();
    _lcd -> refresh();
}

void ScreenController::dispAlert() {
    _lcd -> printString(" Alert ", 22, 2);
    _lcd -> refresh();
    //ThisThread::sleep_for(2s);
}

void ScreenController::dispLocked() {
    _lcd -> printString(" Locked ", 5, 3);
    _lcd -> refresh();
}

void ScreenController::RequestFirstMotion() {
    _lcd -> printString("Set First", 0, 1);
    _lcd -> printString("Motion:", 0, 2);
    _lcd -> refresh();
}

void ScreenController::RequestSecondMotion() {
    _lcd -> printString("Set Second", 0, 1);
    _lcd -> printString("Motion:", 0, 2);
    _lcd -> refresh();
}

void ScreenController::PasswordSetAffirmative() {
    _lcd -> printString("Password Set", 1, 1);
    _lcd -> refresh();
}
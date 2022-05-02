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
    _lcd->turnOff();
}

void ScreenController::customInit() {
    _lcd->init(LPH7366_1); // initialise for LPH7366-1 _lcd (Options are LPH7366_1 and LPH7366_6)                   
    _lcd->setContrast(0.55);  // set contrast to 55%
    _lcd->setBrightness(0.5); // set brightness to 50% (utilises the PWM)
    _lcd->clear();
}

void ScreenController::clearLCD() {
    _lcd->clear();
    _lcd->refresh();
}

void ScreenController::dispAlert() {
    _lcd->drawSprite(35, 12, 14, 13, (int*) alarmSprite_noFill);
    _lcd->printString(" Alert ", 22, 4);
    _lcd->refresh();
}

void ScreenController::dispLocked() {
    _lcd->drawSprite(35, 12, 16, 12, (int*) lockedSprite);
    _lcd->printString(" Locked ", 18, 4);
    _lcd->refresh();
}

void ScreenController::dispUnlocked() {
    _lcd->drawSprite(35, 10, 18, 12, (int*) unlockedSprite);
    _lcd->printString(" Unlocked ", 12, 4);
    _lcd->refresh();
}

void ScreenController::RequestFirstMotion() {
    _lcd->printString("Enter First", 0, 0);
    _lcd->printString("Motion:", 0, 1);
    _lcd->refresh();
}

void ScreenController::RequestSecondMotion() {
    _lcd->printString("Enter Second", 0, 0);
    _lcd->printString("Motion:", 0, 1);
    _lcd->refresh();
}

void ScreenController::PasscodeSetAffirmative() {
    _lcd->printString("Passcode Set", 7, 2);
    _lcd->drawLine(7, 26, 77, 26, 1);
    _lcd->refresh();
}

void ScreenController::RequestPasscode() {
    _lcd->printString("Enter Passcode", 0, 2);
    _lcd->refresh();
}

void ScreenController::CorrectPasscodeMessage() {
    _lcd->printString("Passcode", 18, 2);
    _lcd->printString("Correct!", 19, 3);
    _lcd->refresh();
}

void ScreenController::IncorrectPasscodeMessage() {
    _lcd->printString("Passcode", 18, 2);
    _lcd->printString("Incorrect!", 13, 3);
    _lcd->refresh();
}

void ScreenController::SetupMessageRoutine() {
    _lcd->drawSprite(36, 8, 28, 13, (int*) keySprite);
    _lcd->refresh();
    ThisThread::sleep_for(1s);
    _lcd->printString("LOCK", 15, 2);
    _lcd->refresh();
    ThisThread::sleep_for(500ms);
    _lcd->printString("BOX", 48, 2);
    _lcd->refresh();
    ThisThread::sleep_for(2s);
    _lcd->clear();
    _lcd->printString("Setup", 28, 2);
    _lcd->refresh();

}

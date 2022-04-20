#include "AccessManager.h"
#include <cstdio>

AccessManager::AccessManager(ScreenController *screen, int *_state_ptr) : _passcode(), _input() {
    //                         y     x
    _joystick = new Joystick(PC_3, PC_2);
    _joystick -> Joystick::init();

    //_lockScreen = new ScreenController();
    _lockScreen = screen;
    //get state from state pointer
    _state = *_state_ptr;
}


AccessManager::~AccessManager() {
    delete _joystick;
    delete _lockScreen;
}

void AccessManager::SetPasscode() {

    // store direction in passcode movement 1
    _passcode.movement1 = _EnterFirstMotion();

    while (!isCenter()) {
        ThisThread::sleep_for(100ms);
        isCenter();
    }

    _passcode.movement2 = _EnterSecondMotion();

    // clear LCD
    ThisThread::sleep_for(100ms);
    _lockScreen->clearLCD();
    ThisThread::sleep_for(100ms);
    _lockScreen->PasscodeSetAffirmative();
    ThisThread::sleep_for(1s);
    _lockScreen -> clearLCD();
}

bool AccessManager::isCenter() {
    if (_joystick -> get_direction() == CENTRE) return true;
    else return false;
}

void AccessManager::PrintPasscode() {
    #define code1   _passcode.movement1
    if (code1 == N) {
        printf("Movement 1: N");
    } else if (code1 == NE) {
        printf("Movement 1: NE");
    } else if (code1 == E) {
        printf("Movement 1: E");
    } else if (code1 == SE) {
        printf("Movement 1: SE");
    } else if (code1 == S) {
        printf("Movement 1: S");
    } else if (code1 == SW) {
        printf("Movement 1: SW");
    } else if (code1 == W) {
        printf("Movement 1: W");
    } else if (code1 == NW) {
        printf("Movement 1: NW");
    }
    printf("\n");

    #define code2   _passcode.movement2
    if (code2 == N) {
        printf("Movement 2: N");
    } else if (code2 == NE) {
        printf("Movement 2: NE");
    } else if (code2 == E) {
        printf("Movement 2: E");
    } else if (code2 == SE) {
        printf("Movement 2: SE");
    } else if (code2 == S) {
        printf("Movement 2: S");
    } else if (code2 == SW) {
        printf("Movement 2: SW");
    } else if (code2 == W) {
        printf("Movement 2: W");
    } else if (code2 == NW) {
        printf("Movement 2: NW");
    }
    printf("\n");
}

int AccessManager::EnterPasscode() {
    _lockScreen -> clearLCD();
    ThisThread::sleep_for(100ms);
    _lockScreen -> RequestPasscode();
    ThisThread::sleep_for(500ms);

    _input.movement1 = _EnterFirstMotion();

    while (!isCenter()) {
        ThisThread::sleep_for(100ms);
        isCenter();
    }

    _input.movement2 = _EnterSecondMotion();

    if (PasscodeCheck()) {
        //set state to unlocked
        _lockScreen -> clearLCD();
        ThisThread::sleep_for(100ms);
        _lockScreen -> CorrectPasscodeMessage();
        return 1;

    } else {
        //remain locked
        _lockScreen -> clearLCD();
        ThisThread::sleep_for(100ms);
        _lockScreen -> IncorrectPasscodeMessage();
        return 0;
    }

}

Direction AccessManager::_EnterFirstMotion() {
    Direction d;
    //check again for direction that isn't center
    _lockScreen -> clearLCD();
    ThisThread::sleep_for(100ms);
    _lockScreen -> RequestFirstMotion();
    do {
        d = _joystick -> get_direction();
    } while (d == CENTRE);

    return d;
}

Direction AccessManager::_EnterSecondMotion() {
    Direction d;
    //check again for direction that isn't center
    _lockScreen -> clearLCD();
    ThisThread::sleep_for(100ms);
    _lockScreen -> RequestSecondMotion();
    do {
        d = _joystick -> get_direction();
    } while (d == CENTRE);

    return d;
}

bool AccessManager::PasscodeCheck() {
    if ((_input.movement1 == _passcode.movement1) && (_input.movement2 == _passcode.movement2)) return true;
    else return false;
}
    #include "AccessManager.h"
    #include <cstdio>

    AccessManager::AccessManager(ScreenController *screen) : _passcode() {
        //                         y     x
        _joystick = new Joystick(PC_3, PC_2);
        //_lockScreen = new ScreenController();
        _lockScreen = screen;
    }

    
    AccessManager::~AccessManager() {
        delete _joystick;
        delete _lockScreen;
    }
    

    void AccessManager::SetPasscode() {
        
        Direction d;

        //check for direction that isn't center
        _lockScreen -> clearLCD();
        _lockScreen -> RequestFirstMotion();
        do {
            d = _joystick -> get_direction();
        } while (d == CENTRE);
        
        //store direction in passcode
        _passcode.movement1 = d;

        //check again for direction that isn't center
        _lockScreen -> clearLCD();
        _lockScreen -> RequestFirstMotion();
        do {
            d = _joystick -> get_direction();
        } while (d == CENTRE);

        //store direction in passcode
        _passcode.movement2 = d;

        //clear LCD
        _lockScreen -> clearLCD();
        _lockScreen -> PasswordSetAffirmative();
        
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
    }
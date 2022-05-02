/*  Screen Controller Class
*   Methods for interfacing with LCD
*/

#ifndef SCREEN_CONTROLLER_H
#define SCREEN_CONTROLLER_H

#include "mbed.h"
#include "N5110.h"

class ScreenController {
    public:
    //Constructor
        ScreenController();
    //Destructor
        //~ScreenController();

    //Methods
        //turn Off LCD
        void ScreenOff();
        //custom initialisation of LCD
        void customInit();
        //clears entire LCD
        void clearLCD();
        //LCD Displays Alert and flashes
        void dispAlert();
        //LCD Displays Locked
        void dispLocked();
        //LCD Displays Unlocked
        void dispUnlocked();
        //LCD Displays Set 1st Passcode action
        void RequestFirstMotion();
        //LCD Displays Set 2nd Passcode action
        void RequestSecondMotion();
        //Passcode Set Affirmative
        void PasscodeSetAffirmative();
        //LCD displays enter Passcode
        void RequestPasscode();
        //Correct passcode message
        void CorrectPasscodeMessage();
        //Incorrect passcode message
        void IncorrectPasscodeMessage();

    private:
    //Objects
        //LCD (N5110) Object
        N5110 *_lcd;

    //Sprites
        const int alarmSprite_noFill[14][13] {
            { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, },
            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, },
            { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, },
        };

        const int alarmSprite_Fill[14][13] {
            { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, },
            { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, },
            { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, },
            { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, },
            { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, },
            { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, },
            { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, },
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, },
            { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, },
        };

        const int lockedSprite[16][12] {
            { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, },
        };

        const int unlockedSprite[18][12] {
            { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, },
        };
};

#endif

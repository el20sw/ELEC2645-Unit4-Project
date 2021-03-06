/* Access Manager Class
*   Interface with joystick and lcd to set a passcode or unlock
*/


#ifndef ACCESS_MANAGER_H
#define ACCESS_MANAGER_H

#include "mbed.h"
#include <cstdio>
#include "ScreenController.h"
#include "Joystick.h"

//Passcode Structure
struct Passcode {
    Direction movement1;
    Direction movement2;
    // extend to add further movements for more complex passcodes
};

class AccessManager {
    public:
    //Constructor
        AccessManager(ScreenController *screen);
        AccessManager();
    //Destructor
        ~AccessManager();

    //Methods
        //method to set a passcode
        void SetPasscode();
        //method to enter a passcode returns 0 for locked, 1 for unlocked
        bool EnterPasscode();
        
    // Debugging
        //method to print the passcode
        void PrintPasscode();

    private:
    //Objects
        //Joystick Object
        Joystick *_joystick;
        //Stored Passcode Object
        Passcode _passcode;
        //Inputted Passcode Object
        Passcode _input;
        //Screen Controller Object
        ScreenController *_lockScreen;

    //Methods
        //method to check if joystick is centered
        bool isCenter();
        //method to enter first motion
        Direction _EnterFirstMotion();
        //method to enter second motion
        Direction _EnterSecondMotion();
        //method to check passcode stored against passcode entered
        bool PasscodeCheck();

};

#endif
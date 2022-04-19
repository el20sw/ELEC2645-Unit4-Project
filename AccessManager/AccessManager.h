/* Access Manager Class
*   High level interface with joystick and lcd to set a passcode or unlock
*/


#ifndef ACCESS_MANAGER_H
#define ACCESS_MANAGER_H

#include "mbed.h"
#include <cstdio>
#include "ScreenController.h"
#include "Joystick.h"

//Passcode
struct Passcode {
    Direction movement1;
    Direction movement2;
    // extend to add further movements for more complex passcodes
};

class AccessManager {
    public:
        //constructor
        AccessManager();
        AccessManager(ScreenController *screen);
        //destructor
        ~AccessManager();

        //methods
        //method to set a passcode
        void SetPasscode();
        //method to print the passcode
        void PrintPasscode();
        //method to enter a passcode
        void EnterPasscode();
        //method to get state of lockbox
        bool isLocked(int state);


    private:
        //Joystick Object
        Joystick *_joystick;
        //Stored Passcode Object
        Passcode _passcode;
        //Inputted Passcode Object
        Passcode _input;
        //Screen Controller Object
        ScreenController *_lockScreen;

        //method to check if joystick is centered
        bool isCenter();
        //method to enter first motion
        Direction _EnterFirstMotion();
        //method to enter second motion
        Direction _EnterSecondMotion();

};

#endif
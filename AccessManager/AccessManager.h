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


        private:
            //Joystick Object
            Joystick *_joystick;
            //Passcode Object
            Passcode _passcode;
            //Screen Controller Object
            ScreenController *_lockScreen;

    };

    #endif
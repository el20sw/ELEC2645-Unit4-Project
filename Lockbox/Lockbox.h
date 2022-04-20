/*  Lockbox Class
*   Methods for interfacing with various hardware
*   and general IO for Safe system
*/

#ifndef LOCKBOX_H
#define LOCKBOX_H

#include "mbed.h"
#include "AccessManager.h"
#include "ScreenController.h"
#include "ForceSensor.h"
#include "Alarm.h"
#include "TempSensor.h"

class Lockbox {
    
    public:
        //constructor
        Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin);
        
        //variables
        int g_change_state_flag = 0;

        //methods

        /* Access Manager */
            //Initialise Access Manager
            void AccessManagerInit();
            //Get a password input and unlock if true
            void LockboxStateChange();
            //Method to show passcode
            void ShowPasscode();
            //Method to print the current state - locked or unlocked
            void PrintState(int state);
            //Method to get state
            int GetState();
            //Method to display state on Screen
            void DisplayState();

        //Sounds single note when FSR exceeds 60%
        void PlayForceAlarm();
        
    private:
        //Screen Controller object - as pointer
        ScreenController *screen;
        //Force Sensor object - as object
        ForceSensor force_sensor;
        //Alarm Sensor object - as object
        Alarm alarm;
        //Temperature Sensor object - as object
        TempSensor temp_sensor;
        //Access Manager object
        AccessManager *access_manager;

        //variable describing the state of the lockbox - 0 = locked, 1 = unlocked
        int _state = 1;  //starts unlocked
        //int old_state = 1; //keeps track of last state - redundant
        //pointer to the state of the lockbox
        int *state_ptr = &_state;

        /*
        //ticker to poll state
        LowPowerTicker state_ticker;
        //method to change state flag
        void StateTickerISR();
        */
};

#endif
/*  Lockbox Class
*   Methods for interfacing with various hardware
*   and general IO for Safe system
*/

#ifndef LOCKBOX_H
#define LOCKBOX_H

#include "mbed.h"
#include <cstdio>
#include "AccessManager.h"
#include "LockUnlock.h"
#include "ScreenController.h"
#include "ForceSensor.h"
#include "Alarm.h"
#include "TempSensor.h"

class Lockbox {
    
    public:

    //Constructor
        Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin);

    //Methods
    /* Access Manager */
        //Initialise Access Manager
        void AccessManagerInit();
        //Begin routine to either lock of unlock
        void LockboxLockUnlock();
        //Get a password input and unlock if true
        void LockboxStateChange();            
        //Method to get state
        int GetState();        

    /* Force Alarm */
        //Sounds single note when FSR exceeds 60%
        void PlayForceAlarm();

    /* Debugging Methods */
        //Method to print the current state - locked or unlocked
        void PrintState(int state);
        //Method to show passcode
        void ShowPasscode();
        
    private:

    //Objects
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
        //LockUnlock object
        LockUnlock *lock_button;
    
    //Variables
        //variable describing the state of the lockbox - 0 = locked, 1 = unlocked
        volatile int _state = 1;  //starts unlocked
        //int old_state = 1; //keeps track of last state - redundant
        //pointer to the state of the lockbox
        volatile int *state_ptr = &_state;

    //Methods

};

#endif

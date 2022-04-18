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
        
        //methods
        //Sounds single note when FSR exceeds 60%
        void PlayForceAlarm();
        //Initialise Access Manager
        void AccessManagerInit();
        //Method to show passcode
        void ShowPasscode();
        //change

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

};

#endif
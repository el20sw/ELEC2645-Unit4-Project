/*  Lockbox Class
*   Methods for interfacing with various hardware
*   and general IO for Safe system
*/

#ifndef LOCKBOX_H
#define LOCKBOX_H

#include "mbed.h"
#include "Joystick.h"
#include "ScreenController.h"
#include "ForceSensor.h"
#include "Alarm.h"
#include "TempSensor.h"

class Lockbox : 
    public ForceSensor, 
    public Alarm, 
    public TempSensor {
    
    public:
        //constructor
        Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin);

        //LCD Controller object
        ScreenController *lcd_control;

        //methods
        //Sounds single note when FSR exceeds 60%
        void PlayForceAlarm();

};





#endif
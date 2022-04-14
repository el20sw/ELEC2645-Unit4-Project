/*  Lockbox Class
*   Methods for interfacing with various hardware
*   and general IO for Safe system
*/

#ifndef LOCKBOX_H
#define LOCKBOX_H

#include "mbed.h"
#include "Joystick.h"
#include "LCD_Controller.h"
#include "FSR_Sensor.h"
#include "Alarm.h"
#include "Temp_Sensor.h"

class Lockbox : 
    public FSR_Sensor, 
    public Alarm, 
    public Temp_Sensor {
    
    public:
        //constructor
        Lockbox(PinName fsrPin, PinName buzzerPin, PinName tmpPin);

        //LCD Controller object
        LCD_Controller *lcd_control;

        //methods
        //Sounds single note when FSR exceeds 60%
        void fsr_alarm();

};





#endif
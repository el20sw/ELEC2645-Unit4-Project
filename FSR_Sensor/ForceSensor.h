/*  FSR Sensor Class
*   Used to interface with FSR sensor
*/

#ifndef FORCE_SENSOR_H
#define FORCE_SENSOR_H

#include "mbed.h"
#include <cstdio>

class ForceSensor {
    public:
        //constructors
        ForceSensor(PinName fsrPin);
        //destructors
        ~ForceSensor();
        //mutators
        void ReadFSR();
            // Reads from the assigned pin and assigns to a variable
        void SetThresholdFSR(float MaxForceValue);       
            //method to set threshold FSR - currently redundant
        //accessors
        float GetForceValue();                         
            //returns FSR sensor data as float
        void PrintForceValue();                              
             //method to print FSR data to monitor as percentage

    private:
        AnalogIn *_inputPin;

        float _ForceValue;
        float _MaxForceValue;

        //friend class Lockbox;
};

#endif
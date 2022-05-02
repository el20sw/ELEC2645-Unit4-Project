/*  FSR Sensor Class
*   Used to interface with FSR sensor
*/

#ifndef FORCE_SENSOR_H
#define FORCE_SENSOR_H

#include "mbed.h"
#include <cstdio>

class ForceSensor {
    public:
    //Constructor
        ForceSensor(PinName fsrPin);
    //Destructor
        ~ForceSensor();
    //Methods
        //mutators
        // Reads from the assigned pin and assigns to a variable
        void ReadFSR();
        //method to set threshold FSR - currently redundant
        void SetThresholdFSR(float MaxForceValue);       
            
        //accessors
        //returns FSR sensor data as float
        float GetForceValue();                         
        //method to print FSR data to monitor as percentage   
        void PrintForceValue();                                  

    private:
    //Objects
        AnalogIn *_inputPin;

    //Variables
        float _ForceValue;
        float _MaxForceValue;

};

#endif

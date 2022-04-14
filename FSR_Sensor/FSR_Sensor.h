/*  FSR Sensor Class
*   Used to interface with FSR sensor
*/

#ifndef FSR_SENSOR_H
#define FSR_SENSOR_H

#include "mbed.h"
#include <cstdio>

class FSR_Sensor {
    public:
        //constructors
        FSR_Sensor(PinName fsrPin);
        //destructors
        ~FSR_Sensor();
        //mutators
        void set_FSR();
            // Reads from the assigned pin and assigns to a variable
        void set_max_FSR(float max_FSR);       
            //method to set threshold FSR - currently redundant
        //accessors
        float get_FSR();                         
            //returns FSR sensor data as float
        void print_FSR();                              
             //method to print FSR data to monitor as percentage

    private:
        AnalogIn *_inputPin;

        float _FSR_Val;
        float _max_FSR;

        //friend class Lockbox;
};

#endif
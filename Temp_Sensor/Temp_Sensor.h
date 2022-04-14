/*  Temp Sensor Class
*   Used to interface with temp sensor
*/

#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "mbed.h"

class Temp_Sensor{
    public:
        //constructor
        Temp_Sensor(PinName tmpPin);
        //mutators
        void set_Temp();
            //assigns read value to _temp variable
        void set_MaxTemp(int maxTemp);
        //accessors
        float get_Temp();   
            //returns current temperature Value
        bool isExceeded();
            //returns true if current temperature value exceeds setTemp
        void print_Temp();
            //method to print Temp data to monitor in celcius

    private:
        AnalogIn *_inputPin;

        float _temp;
        float _maxTemp;

        //friend class Lockbox;


};

#endif


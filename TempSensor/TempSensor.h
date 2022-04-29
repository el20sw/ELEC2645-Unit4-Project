/*  Temp Sensor Class
*   Used to interface with temp sensor
*/

#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "mbed.h"

class TempSensor {
    public:
        //constructor
        TempSensor(PinName tmpPin);
        //mutators
        void ReadTemp();
            //assigns read value to _TempValue variable
        void SetThresholdTemp(int maxTemp);
        //accessors
        float GetTempValue();   
            //returns current temperature Value
        bool isExceeded();
            //returns true if current temperature value exceeds setTemp
        void PrintTempValue();
            //method to print Temp data to monitor in celcius

    private:
        AnalogIn *_inputPin;

        float _TempValue;
        float _MaxTempValue;

        //friend class Lockbox;


};

#endif

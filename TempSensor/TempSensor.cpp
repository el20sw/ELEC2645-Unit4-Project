#include "TempSensor.h"

// **********************************************************************
// Constructor
TempSensor::TempSensor(PinName tmpPin){
    _inputPin = new AnalogIn(tmpPin);
}

// **********************************************************************
// Public Methods
//mutators
void TempSensor::ReadTemp(){
    _TempValue = _inputPin -> read();
}

void TempSensor::SetThresholdTemp(int maxTemp){
    _MaxTempValue = (float) maxTemp;
}

//accessors
float TempSensor::GetTempValue(){
    return _TempValue;
}

bool TempSensor::isExceeded(){
    if (_TempValue > _MaxTempValue) {
        return true;
    } else {
        return false;
    }
}

void TempSensor::PrintTempValue(){
    ThisThread::sleep_for(100ms);
    printf("Temperature = %.3f\n", _TempValue);
}
#include "TempSensor.h"

TempSensor::TempSensor(PinName tmpPin){
    _inputPin = new AnalogIn(tmpPin);
}

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
    printf("Temperature = %.3f\n", 1 / _TempValue);
}
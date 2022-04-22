#include "ForceSensor.h"

//Constructors
ForceSensor::ForceSensor(PinName fsrPin){
    _inputPin = new AnalogIn(fsrPin);
}

//Destructors
ForceSensor::~ForceSensor(){
    delete _inputPin;
}

//mutators
void ForceSensor::ReadFSR(){
    _ForceValue = _inputPin -> read();
}

void ForceSensor::SetThresholdFSR(float MaxForceValue){
    _MaxForceValue = MaxForceValue;
}

//accessors
float ForceSensor::GetForceValue(){
    return _ForceValue;
}

void ForceSensor::PrintForceValue(){
    printf("Force Val = %.3f%%\n", _ForceValue * 100);
}




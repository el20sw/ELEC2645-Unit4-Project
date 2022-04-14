#include "FSR_Sensor.h"

//constructors
FSR_Sensor::FSR_Sensor(PinName fsrPin){
    _inputPin = new AnalogIn(fsrPin);
}

//destructors
FSR_Sensor::~FSR_Sensor(){
    delete _inputPin;
}

//mutators
void FSR_Sensor::set_FSR(){
    _FSR_Val = _inputPin -> read();
}

void FSR_Sensor::set_max_FSR(float max_FSR){
    _max_FSR = max_FSR;
}

//accessors
float FSR_Sensor::get_FSR(){
    return _FSR_Val;
}

void FSR_Sensor::print_FSR(){
    printf("Force Val = %.3f%%\n", _FSR_Val * 100);
}




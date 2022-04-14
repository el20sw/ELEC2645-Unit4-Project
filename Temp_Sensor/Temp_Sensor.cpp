#include "Temp_Sensor.h"

Temp_Sensor::Temp_Sensor(PinName tmpPin){
    _inputPin = new AnalogIn(tmpPin);
}

//mutators
void Temp_Sensor::set_Temp(){
    _temp = _inputPin -> read();
}

void Temp_Sensor::set_MaxTemp(int maxTemp){
    _maxTemp = (float) maxTemp;
}

//accessors
float Temp_Sensor::get_Temp(){
    return _temp;
}

bool Temp_Sensor::isExceeded(){
    if (_temp > _maxTemp) {
        return true;
    } else {
        return false;
    }
}

void Temp_Sensor::print_Temp(){
    printf("Temperature = %.3f\n", 1 / _temp);
}
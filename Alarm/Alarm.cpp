#include "Alarm.h"

Alarm::Alarm(PinName buzzerPin) : _alarmPin(buzzerPin) {
   //_alarmPin = new PwmOut(buzzerPin);
}

/*
Alarm::~Alarm(){
    delete _alarmPin;
}
*/

void Alarm::play_note(int frequency){
    _alarmPin.period_us((float) 1000000.0f/ (float) frequency);
    //_alarmPin -> period_us((float) 1000000.0f/ (float) frequency);
    _alarmPin.pulsewidth_us((_alarmPin.read_period_us())/2);
    //_alarmPin -> pulsewidth_us((_alarmPin -> read_period_us())/2);
    ThisThread::sleep_for(500ms);
}

void Alarm::setpulse_us(int pulse_us){
    _alarmPin.pulsewidth_us(pulse_us);
}
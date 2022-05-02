#include "Alarm.h"

// **********************************************************************
// Constructor
Alarm::Alarm(PinName buzzerPin) : _alarmPin(buzzerPin) {
   //_alarmPin = new PwmOut(buzzerPin);
}

// **********************************************************************
// Public Methods
void Alarm::PlayNote(int frequency){
    _alarmPin.period_us((float) 1000000.0f/ (float) frequency);
    _alarmPin.pulsewidth_us((_alarmPin.read_period_us())/2);
    ThisThread::sleep_for(500ms);
}

void Alarm::SetPulse_us(int pulse_us){
    _alarmPin.pulsewidth_us(pulse_us);
}

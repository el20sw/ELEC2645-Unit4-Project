/*  FSR Alarm Class
*   Used to interface with buzzer
*/

#ifndef ALARM_H
#define ALARM_H

#include "mbed.h"

//note definitions
#define NOTE_C4  262    //octave 4 - middle c
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

class Alarm {
    public:
        //constructors
        Alarm(PinName buzzerPin);
        //destructor
        //~Alarm(); redundant when using direct initialisation
        //mutators
        void PlayNote(int frequency);
            //Method to play a single note
        void SetPulse_us(int pulse_us);
            //Method to set the pulsewidth of the signal
        //accessors
        //nothing here for now

    private:
        PwmOut _alarmPin;

        //friend class Lockbox;

};


#endif
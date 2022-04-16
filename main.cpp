//Development Suite for ELEC2645 Unit 4 Project

#include "mbed.h"
#include "N5110.h"
#include "Joystick.h"
#include "Lockbox.h"

BufferedSerial pc(USBTX, USBRX, 115200);
//              FSR  Buzzer  Temp
Lockbox lockbox(PA_1, PA_15, PC_5);


int main(){
    //Initialisation
    lockbox.AccessManagerInit();
    ThisThread::sleep_for(2s);
    lockbox.ShowPasscode();
    
    while (1) {
        
        lockbox.PlayForceAlarm();
        
    }
}
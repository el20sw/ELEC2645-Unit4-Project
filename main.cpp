//Development Suite for ELEC2645 Unit 4 Project

#include "mbed.h"
#include "N5110.h"
#include "Joystick.h"
#include "Lockbox.h"

BufferedSerial pc(USBTX, USBRX, 115200);
//              FSR  Buzzer  Temp
Lockbox lockbox(PA_1, PA_15, PC_3);


int main(){
    while (1) {
        
        lockbox.PlayForceAlarm();
        
    }
}
//Development Suite for ELEC2645 Unit 4 Project

#include "mbed.h"
#include "Lockbox.h"
#include <cstdio>

BufferedSerial pc(USBTX, USBRX, 115200);
//              FSR  Buzzer  Temp
Lockbox lockbox(PA_1, PA_15, PC_5);

//Function Declaration
void ShowPasscode();

int main(){
    lockbox.Runtime();
}

/*
void ShowPasscode() {
    ThisThread::sleep_for(2s);
    lockbox.ShowPasscode();
}
*/

/*
//Debugging
    //Initialisation
    ShowPasscode();
    //Print state
    lockbox.PrintState(lockbox.GetState());
*/
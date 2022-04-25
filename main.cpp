//Development Suite for ELEC2645 Unit 4 Project

#include "mbed.h"
#include "Lockbox.h"
#include <cstdio>

BufferedSerial pc(USBTX, USBRX, 115200);
//              FSR  Buzzer  Temp
Lockbox lockbox(PA_1, PA_15, PC_5);

//Function Declaration
void PasscodeInitialisation();

int main(){
    //Initialisation
    PasscodeInitialisation();

    //Print state
    lockbox.PrintState(lockbox.GetState());

    lockbox.Runtime();

}

void PasscodeInitialisation() {
    ThisThread::sleep_for(2s);
    lockbox.ShowPasscode();
}
//Development Suite for ELEC2645 Unit 4 Project

#include "mbed.h"
#include "Lockbox.h"

BufferedSerial pc(USBTX, USBRX, 115200);
//              FSR  Buzzer  Temp
Lockbox lockbox(PA_1, PA_15, PC_5);

//Function Declaration
void PasscodeInitialisation();

int main(){

    lockbox.ShowPasscode();

    while (1) {

    //Initialisation
    PasscodeInitialisation();

    //Print state
    lockbox.PrintState(lockbox.GetState());

    //Enter a passcode and unlock
    ThisThread::sleep_for(1s);
    lockbox.LockboxStateChange();
    //Print state
    lockbox.PrintState(lockbox.GetState());
    
    /*
    while (1) {
        lockbox.PlayForceAlarm();
    }
    */
}

void PasscodeInitialisation() {
    ThisThread::sleep_for(2s);
    lockbox.ShowPasscode();
}
/* LockUnlock class - interfaces with physical interrupt to
* begin unlcocking procedure or lock lockbox
*/ 

#ifndef LOCK_UNLOCK_H
#define LOCK_UNLOCK_H

#include "mbed.h"

class LockUnlock {
    public:
        //constructor
        LockUnlock(PinName InterruptPin);
        //methods
        void LockUnlockISR() { LockUnlockISR_flag = 1; }
        //variables
        volatile int LockUnlockISR_flag = 0;

    private:
        InterruptIn *_LockUnlockPin;
};

#endif
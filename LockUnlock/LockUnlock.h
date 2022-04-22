/* LockUnlock class - interfaces with physical interrupt to
*  begin unlcocking procedure or lock lockbox
*/ 

#ifndef LOCK_UNLOCK_H
#define LOCK_UNLOCK_H

#include "mbed.h"

class LockUnlock {
    public:
    //Constructor
        LockUnlock(PinName InterruptPin);
    //Methods
        void LockUnlockISR() { _LockUnlockISR_flag = 1; }
        volatile int getISRflag() { return _LockUnlockISR_flag; }
        void setISRflag(int val) { _LockUnlockISR_flag = val; }
        

    private:
    //Objects
        InterruptIn *_LockUnlockPin;
    //Variables
        volatile int _LockUnlockISR_flag = 0;
};

#endif

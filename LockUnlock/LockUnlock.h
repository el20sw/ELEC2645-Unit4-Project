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

    private:
        InterruptIn *_LockUnlockPin;
};

#endif
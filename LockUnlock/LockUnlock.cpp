#include "LockUnlock.h"

LockUnlock::LockUnlock(PinName InterruptPin) {
    _LockUnlockPin = new InterruptIn(InterruptPin);
    _LockUnlockPin->mode(PullNone);
    _LockUnlockPin->rise(callback(this, &LockUnlock::LockUnlockISR));
}

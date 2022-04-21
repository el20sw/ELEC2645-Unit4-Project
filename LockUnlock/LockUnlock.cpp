#include "LockUnlock.h"

LockUnlock::LockUnlock(PinName InterruptPin) {
    _LockUnlockPin = new InterruptIn(InterruptPin);
}
#include "configuration-datatypes.h"

screenData::screenData (int const w, int const h, Uint32 const f):
    width(w), height(h), flags(f) {}

keyRepeatData::keyRepeatData (int const w, int const r):
    wait(w), rate(r) {}

int keyRepeatData::getWaitInSDLFormat () const {
    return 100 * wait;
}

int keyRepeatData::getRateInSDLFormat () const {
    return iRound(1000.0 / rate);
}

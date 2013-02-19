#include "configuration-datatypes.h"
#include "mathematics-functions.h"

screenData::screenData (int w, int h, Uint32 f):
    width(w), height(h), flags(f) {}

keyRepeatData::keyRepeatData (int w, int r):
    wait(w), rate(r) {}

int keyRepeatData::getWaitInSDLFormat () {
    return 100*wait;
}

int keyRepeatData::getRateInSDLFormat () {
    return iRoundAwayFromZero(1000.0 / rate);
}

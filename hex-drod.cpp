#include "hex-drod.h"

hexDrod::hexDrod () {}

bool hexDrod::startup () {
    return true;
}

void hexDrod::shutdown () {}

void hexDrod::loopStep () {}

void hexDrod::render (SDL_Surface* s) {}

screenData hexDrod::getDesiredScreenData () {
    return screenData (
        DEFAULT_DISPLAY_WIDTH,
        DEFAULT_DISPLAY_HEIGHT,
        DEFAULT_SDL_DISPLAY_MODE_FLAGS
    );
}

keyRepeatData hexDrod::getDesiredKeyRepeatData () {
    return keyRepeatData(DEFAULT_KEY_REPEAT_WAIT, DEFAULT_KEY_REPEAT_RATE);
}

#include "hex-drod.h"

hexDrod::hexDrod (): mode(APPLICATION_MODE_INGAME) {}

bool hexDrod::startup () {
    if (SDL_Init(MY_SDL_INIT_FLAGS) < 0) {
        return false;
    }
    displaySurface = SDL_SetVideoMode (
        myScreenData.width, myScreenData.height, 32, myScreenData.flags
    );
    if (displaySurface == NULL) {
        return false;
    }
    SDL_EnableKeyRepeat (
        myKeyRepeatData.getWaitInSDLFormat(),
        myKeyRepeatData.getRateInSDLFormat()
    );
    return true;
}

void hexDrod::shutdown () {
    SDL_Quit();
    running = false;
}

void hexDrod::loopStep () {
    //
}

void hexDrod::render () {
    //
}

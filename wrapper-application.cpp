#include "wrapper-application.h"

wrapperApplication::wrapperApplication (hexDrod* myHexDrod):
    running(true),
    hd(myHexDrod),
    displaySurface(NULL),
    currentScreenData (
        DEFAULT_DISPLAY_WIDTH,
        DEFAULT_DISPLAY_HEIGHT,
        DEFAULT_SDL_DISPLAY_MODE_FLAGS
    ),
    currentKeyRepeatData(DEFAULT_KEY_REPEAT_WAIT, DEFAULT_KEY_REPEAT_RATE) {}

int wrapperApplication::run () {
    if (startup() == false) {
        return -1;
    }
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            handleEvent(&e);
        }
        hd->loopStep();
        hd->render(displaySurface);
    }
    return 0;
}

bool wrapperApplication::startup () {
    if (hd->startup() == false) {
        return false;
    }
    if (SDL_Init(MY_SDL_INIT_FLAGS) < 0) {
        return false;
    }
    currentScreenData = hd->getDesiredScreenData();
    displaySurface = SDL_SetVideoMode (
        currentScreenData.width,
        currentScreenData.height,
        32,
        currentScreenData.flags
    );
    if (displaySurface == NULL) {
        return false;
    }
    currentKeyRepeatData = hd->getDesiredKeyRepeatData();
    SDL_EnableKeyRepeat (
        currentKeyRepeatData.getWaitInSDLFormat(),
        currentKeyRepeatData.getRateInSDLFormat()
    );
    return true;
}

void wrapperApplication::shutdown () {
    SDL_FreeSurface(displaySurface);
    SDL_Quit();
    hd->shutdown();
    running = false;
}

void wrapperApplication::handleEvent (SDL_Event* e) {
    switch (e->type) {
        case SDL_KEYDOWN:
            hd->eventKeyDown(e->key.keysym.sym, e->key.keysym.unicode);
            break;
        case SDL_KEYUP:
            hd->eventKeyUp(e->key.keysym.sym, e->key.keysym.unicode);
            break;
        case SDL_MOUSEMOTION:
            hd->eventMouseMove (
                e->motion.x,
                e->motion.y,
                e->motion.xrel,
                e->motion.yrel,
                (e->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                (e->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0,
                (e->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0
            );
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (e->button.button) {
                case SDL_BUTTON_LEFT:
                    hd->eventMouseLButtonDown(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_MIDDLE:
                    hd->eventMouseMButtonDown(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_RIGHT:
                    hd->eventMouseRButtonDown(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_WHEELUP:
                    hd->eventMouseWheelUp(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_WHEELDOWN:
                    hd->eventMouseWheelDown(e->button.x, e->button.y);
                    break;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            switch (e->button.button) {
                case SDL_BUTTON_LEFT:
                    hd->eventMouseLButtonUp(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_MIDDLE:
                    hd->eventMouseMButtonUp(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_RIGHT:
                    hd->eventMouseRButtonUp(e->button.x, e->button.y);
                    break;
            }
            break;
        case SDL_ACTIVEEVENT:
            switch (e->active.state) {
                case SDL_APPMOUSEFOCUS:
                    e->active.gain ? hd->eventMouseFocus() : hd->eventMouseBlur();
                    break;
                case SDL_APPINPUTFOCUS:
                    e->active.gain ? hd->eventInputFocus() : hd->eventInputBlur();
                    break;
                case SDL_APPACTIVE:
                    e->active.gain ? hd->eventRestore() : hd->eventMinimise();
                    break;
            }
            break;
        case SDL_QUIT:
            hd->shutdown();
            shutdown();
            break;
        case SDL_JOYAXISMOTION:
        case SDL_JOYBALLMOTION:
        case SDL_JOYHATMOTION:
        case SDL_JOYBUTTONDOWN:
        case SDL_JOYBUTTONUP:
            // I don't think there are many people who
            // want to play DROD using a joystick.
        case SDL_VIDEORESIZE:
            // We do not implement resizing of the window at present.
        case SDL_VIDEOEXPOSE:
            // No special action to be taken on exposure of window regions.
        case SDL_SYSWMEVENT:
        default:
            break;
    }
}

#include "sdl-application.h"

sdlApplication::sdlApplication ():
    running(true),
    displaySurface(NULL),
    myScreenData (
        DEFAULT_DISPLAY_WIDTH,
        DEFAULT_DISPLAY_HEIGHT,
        DEFAULT_SDL_DISPLAY_MODE_FLAGS
    ),
    myKeyRepeatData(DEFAULT_KEY_REPEAT_WAIT, DEFAULT_KEY_REPEAT_RATE) {}

int sdlApplication::run () {
    if (startup() == false) {
        return -1;
    }
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            handleEvent(&e);
        }
        loopStep();
        render();
    }
    shutdown();
    return 0;
}

void sdlApplication::handleEvent (SDL_Event* e) {
    switch (e->type) {
        case SDL_KEYDOWN:
            eventKeyDown(e->key.keysym.sym, e->key.keysym.unicode);
            break;
        case SDL_KEYUP:
            eventKeyUp(e->key.keysym.sym, e->key.keysym.unicode);
            break;
        case SDL_MOUSEMOTION:
            eventMouseMove (
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
                    eventMouseLButtonDown(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_MIDDLE:
                    eventMouseMButtonDown(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_RIGHT:
                    eventMouseRButtonDown(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_WHEELUP:
                    eventMouseWheelUp(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_WHEELDOWN:
                    eventMouseWheelDown(e->button.x, e->button.y);
                    break;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            switch (e->button.button) {
                case SDL_BUTTON_LEFT:
                    eventMouseLButtonUp(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_MIDDLE:
                    eventMouseMButtonUp(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_RIGHT:
                    eventMouseRButtonUp(e->button.x, e->button.y);
                    break;
            }
            break;
        case SDL_ACTIVEEVENT:
            switch (e->active.state) {
                case SDL_APPMOUSEFOCUS:
                    e->active.gain ? eventMouseFocus() : eventMouseBlur();
                    break;
                case SDL_APPINPUTFOCUS:
                    e->active.gain ? eventInputFocus() : eventInputBlur();
                    break;
                case SDL_APPACTIVE:
                    e->active.gain ? eventRestore() : eventMinimise();
                    break;
            }
            break;
        case SDL_QUIT:
            running = false;
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
            // We do not currently handle any special window-manager events.
        default:
            break;
    }
}

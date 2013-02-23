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

void sdlApplication::handleEvent (SDL_Event const * const e) {
    switch (e->type) {
        case SDL_KEYDOWN:
            eventKeyDown(e->key.keysym.sym, e->key.keysym.unicode);
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (e->button.button) {
                case SDL_BUTTON_LEFT:
                    eventMouseLButtonDown(e->button.x, e->button.y);
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
                case SDL_BUTTON_MIDDLE:
                    // We do not currently attach any
                    // functionality to middle-clicks.
                    break;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            switch (e->button.button) {
                case SDL_BUTTON_LEFT:
                    eventMouseLButtonUp(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_RIGHT:
                    eventMouseRButtonUp(e->button.x, e->button.y);
                    break;
                case SDL_BUTTON_WHEELUP:
                case SDL_BUTTON_WHEELDOWN:
                case SDL_BUTTON_MIDDLE:
                    // As above, we do not attach any functionality to
                    // middle-clicks. Mouse button up events shouldn't
                    // occur for "wheel up" and "wheel down".
                    break;
            }
            break;
        case SDL_MOUSEMOTION:
            eventMouseMove (
                e->motion.x,
                e->motion.y,
                e->motion.xrel,
                e->motion.yrel,
                (e->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                (e->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0
            );
            break;
        case SDL_ACTIVEEVENT:
            if (e->active.state == SDL_APPACTIVE) {
                // The other possible values of e->active.state are
                // SDL_APPMOUSEFOCUS, which relates to the application gaining
                // or losing mouse focus, and SDL_APPINPUTFOCUS, which does the
                // same thing but for keyboard input focus. We don't have
                // anything special we want to happen in either of these cases.
                e->active.gain ? eventRestore() : eventMinimise();
            }
            break;
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYUP:
            // We don't currently care to track key-up events.
        case SDL_JOYAXISMOTION:
        case SDL_JOYBALLMOTION:
        case SDL_JOYHATMOTION:
        case SDL_JOYBUTTONDOWN:
        case SDL_JOYBUTTONUP:
            // I don't think there are many people who want to play DROD using a
            // joystick. Anyway, even if they do, we do not currently support that.
        case SDL_VIDEORESIZE:
            // We do not currently implement user resizing of the window.
        case SDL_VIDEOEXPOSE:
            // No special action to be taken on exposure of window regions.
        case SDL_SYSWMEVENT:
            // We do not currently handle any special window-manager events.
            break;
    }
}

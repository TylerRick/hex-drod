#ifndef WRAPPER_APPLICATION_H
    #define WRAPPER_APPLICATION_H

    #include <SDL.h>
    #include "hex-drod.h"

    class wrapperApplication {
        protected:
            bool running;
            hexDrod* hd;
            SDL_Surface* displaySurface;
            screenData currentScreenData;
            keyRepeatData currentKeyRepeatData;
            bool startup ();
            void shutdown ();
            void handleEvent (SDL_Event* Event);
        public:
            wrapperApplication (hexDrod* myHexDrod);
            int run ();
    };
#endif

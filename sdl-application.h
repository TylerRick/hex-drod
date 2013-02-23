#ifndef SDL_APPLICATION_H
    #define SDL_APPLICATION_H

    #include <SDL.h>
    #include "configuration-datatypes.h"
    #include "graphics-constants.h"
    #include "gameplay-constants.h"

    class sdlApplication {
        protected:
            bool running;
            SDL_Surface * displaySurface;
            screenData myScreenData;
            keyRepeatData myKeyRepeatData;
            void handleEvent (SDL_Event const * const Event);
            virtual bool startup () = 0;
            virtual void shutdown () = 0;
            virtual void loopStep () = 0;
            virtual void render () = 0;
            virtual void eventMouseMove (
                int const absX, int const absY, int const relX, int const relY,
                bool const LButtonDown, bool const RButtonDown
            ) = 0;
            virtual void eventMouseLButtonDown (int const x, int const y) = 0;
            virtual void eventMouseLButtonUp (int const x, int const y) = 0;
            virtual void eventMouseRButtonDown (int const x, int const y) = 0;
            virtual void eventMouseRButtonUp (int const x, int const y) = 0;
            virtual void eventMouseWheelUp (int const x, int const y) = 0;
            virtual void eventMouseWheelDown (int const x, int const y) = 0;
            virtual void eventKeyDown (SDLKey const sym, Uint16 const codepoint) = 0;
            virtual void eventMinimise () = 0;
            virtual void eventRestore () = 0;
        public:
            sdlApplication ();
            int run ();
    };
#endif

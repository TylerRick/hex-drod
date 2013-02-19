#ifndef SDL_APPLICATION_H
    #define SDL_APPLICATION_H

    #include <SDL.h>
    #include "configuration-datatypes.h"
    #include "graphics-constants.h"
    #include "gameplay-constants.h"

    class sdlApplication {
        protected:
            bool running;
            SDL_Surface* displaySurface;
            screenData myScreenData;
            keyRepeatData myKeyRepeatData;
            void handleEvent (SDL_Event* Event);
            virtual bool startup () = 0;
            virtual void shutdown () = 0;
            virtual void loopStep () = 0;
            virtual void render () = 0;
            virtual void eventKeyDown (SDLKey sym, Uint16 codepoint) = 0;
            virtual void eventKeyUp (SDLKey sym, Uint16 codepoint) = 0;
            virtual void eventMouseLButtonDown (int x, int y) = 0;
            virtual void eventMouseLButtonUp (int x, int y) = 0;
            virtual void eventMouseRButtonDown (int x, int y) = 0;
            virtual void eventMouseRButtonUp (int x, int y) = 0;
            virtual void eventMouseWheelUp (int x, int y) = 0;
            virtual void eventMouseWheelDown (int x, int y) = 0;
            virtual void eventMouseMove (
                int absX, int absY, int relX, int relY,
                bool LButtonDown, bool MButtonDown, bool RButtonDown
            ) = 0;
            virtual void eventMinimise () = 0;
            virtual void eventRestore () = 0;
        public:
            sdlApplication ();
            int run ();
    };
#endif

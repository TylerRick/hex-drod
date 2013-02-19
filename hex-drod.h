#ifndef HEX_DROD_H
    #define HEX_DROD_H

    #include <SDL.h>
    #include "configuration-messages.h"
    #include "application-constants.h"
    #include "graphics-constants.h"
    #include "gameplay-constants.h"

    class hexDrod {
        public:
            hexDrod ();
            bool startup ();
            void shutdown ();
            void loopStep ();
            void render (SDL_Surface* s);
            void eventMouseFocus ();
            void eventMouseBlur ();
            void eventInputFocus ();
            void eventInputBlur ();
            void eventMinimise ();
            void eventRestore ();
            void eventMouseMove (
                int absX, int absY, int relX, int relY,
                bool LButtonDown, bool MButtonDown, bool RButtonDown
            );
            void eventMouseLButtonDown (int x, int y);
            void eventMouseLButtonUp (int x, int y);
            void eventMouseMButtonDown (int x, int y);
            void eventMouseMButtonUp (int x, int y);
            void eventMouseRButtonDown (int x, int y);
            void eventMouseRButtonUp (int x, int y);
            void eventMouseWheelUp (int x, int y);
            void eventMouseWheelDown (int x, int y);
            void eventKeyDown (SDLKey sym, Uint16 codepoint);
            void eventKeyUp (SDLKey sym, Uint16 codepoint);
            screenData getDesiredScreenData ();
            keyRepeatData getDesiredKeyRepeatData ();
    };

#endif

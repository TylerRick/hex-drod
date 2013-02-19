#ifndef HEX_DROD_H
    #define HEX_DROD_H

    #include <SDL.h>
    #include "sdl-application.h"
    #include "application-constants.h"

    class hexDrod: public sdlApplication {
        private:
            int mode;
        public:
            hexDrod ();
            virtual bool startup ();
            virtual void shutdown ();
            virtual void loopStep ();
            virtual void render ();
            virtual void eventMouseFocus ();
            virtual void eventMouseBlur ();
            virtual void eventInputFocus ();
            virtual void eventInputBlur ();
            virtual void eventMinimise ();
            virtual void eventRestore ();
            virtual void eventMouseMove (
                int absX, int absY, int relX, int relY,
                bool LButtonDown, bool MButtonDown, bool RButtonDown
            );
            virtual void eventMouseLButtonDown (int x, int y);
            virtual void eventMouseLButtonUp (int x, int y);
            virtual void eventMouseMButtonDown (int x, int y);
            virtual void eventMouseMButtonUp (int x, int y);
            virtual void eventMouseRButtonDown (int x, int y);
            virtual void eventMouseRButtonUp (int x, int y);
            virtual void eventMouseWheelUp (int x, int y);
            virtual void eventMouseWheelDown (int x, int y);
            virtual void eventKeyDown (SDLKey sym, Uint16 codepoint);
            virtual void eventKeyUp (SDLKey sym, Uint16 codepoint);
    };
#endif

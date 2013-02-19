#ifndef HEX_DROD_H
    #define HEX_DROD_H

    #include "sdl-application.h"
    #include "application-constants.h"

    class hexDrod: public sdlApplication {
        protected:
            int mode;
            virtual bool startup ();
            virtual void shutdown ();
            virtual void loopStep ();
            virtual void render ();
            virtual void eventKeyDown (SDLKey sym, Uint16 codepoint);
            virtual void eventKeyUp (SDLKey sym, Uint16 codepoint);
            virtual void eventMouseLButtonDown (int x, int y);
            virtual void eventMouseLButtonUp (int x, int y);
            virtual void eventMouseRButtonDown (int x, int y);
            virtual void eventMouseRButtonUp (int x, int y);
            virtual void eventMouseWheelUp (int x, int y);
            virtual void eventMouseWheelDown (int x, int y);
            virtual void eventMouseMove (
                int absX, int absY, int relX, int relY,
                bool LButtonDown, bool MButtonDown, bool RButtonDown
            );
            virtual void eventMinimise ();
            virtual void eventRestore ();
        public:
            hexDrod ();
    };
#endif

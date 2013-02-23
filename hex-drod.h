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
            virtual void eventMouseMove (
                int const absX, int const absY, int const relX, int const relY,
                bool const LButtonDown, bool const RButtonDown
            );
            virtual void eventMouseLButtonDown (int const x, int const y);
            virtual void eventMouseLButtonUp (int const x, int const y);
            virtual void eventMouseRButtonDown (int const x, int const y);
            virtual void eventMouseRButtonUp (int const x, int const y);
            virtual void eventMouseWheelUp (int const x, int const y);
            virtual void eventMouseWheelDown (int const x, int const y);
            virtual void eventKeyDown (SDLKey const sym, Uint16 const codepoint);
            virtual void eventMinimise ();
            virtual void eventRestore ();
        public:
            hexDrod ();
    };
#endif

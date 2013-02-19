#ifndef CONFIGURATION_DATATYPES_H
    #define CONFIGURATION_DATATYPES_H

    #include <SDL.h>

    class screenData {
        public:
            screenData (int w, int h, Uint32 f);
            int width;
            int height;
            Uint32 flags;
    };

    class keyRepeatData {
        public:
            keyRepeatData (int w, int r);
            int wait; // Desired wait, in tenths of a second
            int rate; // Desired number of repeats per second
            int getWaitInSDLFormat ();
            int getRateInSDLFormat ();
    };

#endif

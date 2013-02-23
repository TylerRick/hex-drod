#ifndef CONFIGURATION_DATATYPES_H
    #define CONFIGURATION_DATATYPES_H

    #include <SDL.h>
    #include "mathematics-functions.h"

    class screenData {
        public:
            screenData (int const w, int const h, Uint32 const f);
            int width;
            int height;
            Uint32 flags;
    };

    class keyRepeatData {
        public:
            keyRepeatData (int const w, int const r);
            int wait; // Desired wait, in tenths of a second
            int rate; // Desired number of repeats per second
            int getWaitInSDLFormat () const;
            int getRateInSDLFormat () const;
    };

#endif

#ifndef COORDS_H
    #define COORDS_H

    #include "mathematics-functions.h"

    namespace coords {
        int xytoz (int const x, int const y);
        int xztoy (int const x, int const z);
        int yztox (int const y, int const z);
            // Given two major coordinates, find the corresponding value
            // for the third major coordinate.
        int xytoa (int const x, int const y);
        int xytob (int const x, int const y);
        int xytoc (int const x, int const y);
        int xztoc (int const x, int const z);
        int xztoa (int const x, int const z);
        int xztob (int const x, int const z);
        int yztob (int const y, int const z);
        int yztoc (int const y, int const z);
        int yztoa (int const y, int const z);
            // Given two major coordinates, find the corresponding value
            // for the indicated minor coordinate.
        bool darkHex (int const a);
            // Determine whether the supplied global a-coordinate is that of a dark hex.
    }
#endif

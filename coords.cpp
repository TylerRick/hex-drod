#include "coords.h"

int coords::xytoz (int const x, int const y) {return -(x + y);}
int coords::xztoy (int const x, int const z) {return -(x + z);}
int coords::yztox (int const y, int const z) {return -(y + z);}

int coords::xytoa (int const x, int const y) {return  (x + 2*y);}
int coords::xytob (int const x, int const y) {return -(y + 2*x);}
int coords::xytoc (int const x, int const y) {return  (x -   y);}
int coords::xztoc (int const x, int const z) {return  (z + 2*x);}
int coords::xztoa (int const x, int const z) {return -(x + 2*z);}
int coords::xztob (int const x, int const z) {return  (z -   x);}
int coords::yztob (int const y, int const z) {return  (y + 2*z);}
int coords::yztoc (int const y, int const z) {return -(z + 2*y);}
int coords::yztoa (int const y, int const z) {return  (y -   z);}

bool coords::darkHex (int const a) {
    return (bool)(nonnegativeRemainderQuotient(a, 2) % 2);
}

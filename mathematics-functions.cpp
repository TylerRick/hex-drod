#include "mathematics-functions.h"

int iRoundAwayFromZero (float f) {
    return (int)(f > 0 ? floor(f + 0.5) : ceil(f - 0.5));
}

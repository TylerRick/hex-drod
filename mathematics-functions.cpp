#include "mathematics-functions.h"

int nonnegativeRemainder (int const a, int const b) {
    int r = a % b;
    return r + (r < 0 ? b : 0);
}

int nonnegativeRemainderQuotient (int const a, int const b) {
    return (a - nonnegativeRemainder(a, b)) / b;
}

int iRound (float const f) {
    assert(f > -1e16);
    assert(f <  1e16);
    return (int)(f > 0 ? floor(f + 0.5) : ceil(f - 0.5));
}

int zCoord (int const x, int const y) {
    return -(x + y);
}

int aCoord (int const x, int const y) {
    return x + 2*y;
}

int bCoord (int const x, int const y) {
    return -(y + 2*x);
}

int cCoord (int const x, int const y) {
    return x - y;
}

bool darkHex (int const a) {
    return (bool)(nonnegativeRemainderQuotient(a, 2) % 2);
}

bool forceArrowPermitsMovement (int const forceArrowDirection, int const movementDirection) {
    static bool const movementPermitted [7] [6] = {
        {true , true , false, false, false, true }, // Force arrow pointing north
        {true , true , true , false, false, false}, // Force arrow pointing northeast
        {false, true , true , true , false, false}, // Force arrow pointing southeast
        {false, false, true , true , true , false}, // Force arrow pointing south
        {false, false, false, true , true , true }, // Force arrow pointing southwest
        {true , false, false, false, true , true }, // Force arrow pointing northwest
        {true , true , true , true , true , true }  // No force arrow present on hex
    };
    assert(forceArrowDirection >= 0);
    assert(forceArrowDirection <  7);
    assert(movementDirection   >= 0);
    assert(movementDirection   <  6);
    return movementPermitted[forceArrowDirection][movementDirection];
}

bool stepBlockerPermitsMovement (int const stepBlockerTypes, int const movementDirection) {
    static bool const movementPermitted [4] [6] = {
        {true , true , true , true , true , true }, // No step blocker present on hex
        {false, true , false, true , false, true }, // Step blocker preventing positive-axis movement
        {true , false, true , false, true , false}, // Step blocker preventing negative-axis movement
        {false, false, false, false, false, false}  // Both types of step blockers are present
    };
    assert(stepBlockerTypes  >= 0);
    assert(stepBlockerTypes  <  4);
    assert(movementDirection >= 0);
    assert(movementDirection <  6);
    return movementPermitted[stepBlockerTypes][movementDirection];
}

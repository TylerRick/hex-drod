#include "mathematics-functions.h"

int iRoundAwayFromZero (float f) {
    assert(f > -1e16);
    assert(f <  1e16);
    return (int)(f > 0 ? floor(f + 0.5) : ceil(f - 0.5));
}

bool forceArrowPermitsMovement (const int forceArrowDirection, const int movementDirection) {
    static const bool movementPermitted[7][6] = {
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

bool stepBlockerPermitsMovement (const int stepBlockerTypes, const int movementDirection) {
    static const bool movementPermitted[4][6] = {
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

#ifndef MATHEMATICS_FUNCTIONS_H
    #define MATHEMATICS_FUNCTIONS_H

    #include <assert.h>
    #include <math.h>

    int iRoundAwayFromZero (float f);
        // This function asserts that its argument is less than 10^16 in
        // absolute value. This is because the method it uses to perform
        // rounding may give inaccurate results for floats that are very large
        // in absolute value.

    bool forceArrowPermitsMovement (const int forceArrowDirection, const int movementDirection);
    bool stepBlockerPermitsMovement (const int stepBlockerTypes, const int movementDirection);
        // These functions perform unchecked array dereferencing (against
        // appropriate static const arrays) using the supplied integer
        // arguments. forceArrowDirection should be in the range 0 to 6
        // inclusive; stepBlockerTypes should be in the range 0 to 3 inclusive;
        // and in each case movementDirection should be in the range 0 to 5
        // inclusive. Each function asserts that these requirements are
        // satisfied.
#endif

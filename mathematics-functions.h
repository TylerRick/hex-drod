#ifndef MATHEMATICS_FUNCTIONS_H
    #define MATHEMATICS_FUNCTIONS_H

    #include <assert.h>
    #include <math.h>

    int nonnegativeRemainder (int const a, int const b);
    int nonnegativeRemainderQuotient (int const a, int const b);
        // These functions compute the remainder and quotient respectively on
        // dividing a by b. The remainder will be nonnegative (a property not
        // guaranteed by the standard "%" and "/" operators if one or both of
        // a and b is negative).

    int iRound (float const f);
        // This function rounds a float to the nearest integer. In the case of
        // a tie, it rounds away from zero. It asserts that its argument is
        // less than 10^16 in absolute value; this is because the method used
        // to perform rounding may give inaccurate results for floats that are
        // very large in absolute value.

    bool forceArrowPermitsMovement (int const forceArrowDirection, int const movementDirection);
    bool stepBlockerPermitsMovement (int const stepBlockerTypes, int const movementDirection);
        // These functions perform unchecked array dereferencing (against
        // appropriate static const arrays) using the supplied integer
        // arguments. forceArrowDirection should be in the range 0 to 6
        // inclusive; stepBlockerTypes should be in the range 0 to 3 inclusive;
        // and in each case movementDirection should be in the range 0 to 5
        // inclusive. Each function asserts that these requirements are
        // satisfied.
#endif

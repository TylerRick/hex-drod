#include "axis-translation-bounded-region.h"

axisTranslationBoundedRegion::axisTranslationBoundedRegion (
    coordinateRange const xr,
    coordinateRange const yr,
    coordinateRange const zr,
    coordinateRange const ar,
    coordinateRange const br,
    coordinateRange const cr
): xRange(xr), yRange(yr), zRange(zr),
   aRange(ar), bRange(br), cRange(cr),
   rangesOptimised(false), hexCount(-1) {}

axisTranslationBoundedRegion::axisTranslationBoundedRegion (
    int const x1, int const x2,
    int const y1, int const y2,
    int const z1, int const z2,
    int const a1, int const a2,
    int const b1, int const b2,
    int const c1, int const c2
): xRange(x1, x2), yRange(y1, y2), zRange(z1, z2),
   aRange(a1, a2), bRange(b1, b2), cRange(c1, c2),
   rangesOptimised(false), hexCount(-1) {}

axisTranslationBoundedRegion axisTranslationBoundedRegion::checked (
    int x1, int x2, int y1, int y2, int z1, int z2,
    int a1, int a2, int b1, int b2, int c1, int c2
) {
    return axisTranslationBoundedRegion (
        coordinateRange::checked(x1, x2),
        coordinateRange::checked(y1, y2),
        coordinateRange::checked(z1, z2),
        coordinateRange::checked(a1, a2),
        coordinateRange::checked(b1, b2),
        coordinateRange::checked(c1, c2)
    );
}

axisTranslationBoundedRegion axisTranslationBoundedRegion::copyWithOptimisedRanges
    () const {
    axisTranslationBoundedRegion newATBR = *this;
    newATBR.optimiseRanges();
    return newATBR;
}

bool axisTranslationBoundedRegion::xyInRegion (int const x, int const y) const {
    return zRange.inRange(coords::xytoz(x, y)) &&
           aRange.inRange(coords::xytoa(x, y)) &&
           bRange.inRange(coords::xytob(x, y)) &&
           cRange.inRange(coords::xytoc(x, y));
}

bool axisTranslationBoundedRegion::xzInRegion (int const x, int const z) const {
    return yRange.inRange(coords::xztoy(x, z)) &&
           aRange.inRange(coords::xztoa(x, z)) &&
           bRange.inRange(coords::xztob(x, z)) &&
           cRange.inRange(coords::xztoc(x, z));
}

bool axisTranslationBoundedRegion::yzInRegion (int const y, int const z) const {
    return xRange.inRange(coords::yztox(y, z)) &&
           aRange.inRange(coords::yztoa(y, z)) &&
           bRange.inRange(coords::yztob(y, z)) &&
           cRange.inRange(coords::yztoc(y, z));
}

int xRowSize (int const x) const {
    //
}

int axisTranslationBoundedRegion::numHexes () const {
    if (hexCount >= 0) {return hexCount;}
    hexCount = 0;
    axisTranslationBoundedRegion operatingATBR =
        rangesOptimised ? *this : copyWithOptimisedRanges();
    int xRangeLength = operatingATBR.xRange.length();
    int yRangeLength = operatingATBR.yRange.length();
    int zRangeLength = operatingATBR.zRange.length();
    if (xRangeLength < 0 || yRangeLength < 0 || zRangeLength < 0) {
        return 0;
    }
    int greatestRange, outerMin, outerMax, innerMin, innerMax;
    if (zRangeLength >= xRangeLength && zRangeLength >= yRangeLength) {
        greatestRange = COORDINATE_IDENTIFIER_Z;
        outerMin = operatingATBR.xRange.getMin();
        outerMax = operatingATBR.xRange.getMax();
        innerMin = operatingATBR.yRange.getMin();
        innerMax = operatingATBR.yRange.getMax();
    } else {
        if (yRangeLength >= xRangeLength && yRangeLength >= zRangeLength) {
            greatestRange = COORDINATE_IDENTIFIER_Y;
            outerMin = operatingATBR.xRange.getMin();
            outerMax = operatingATBR.xRange.getMax();
        } else {
            greatestRange = COORDINATE_IDENTIFIER_X;
            outerMin = operatingATBR.yRange.getMin();
            outerMax = operatingATBR.yRange.getMax();
        }
        innerMin = operatingATBR.zRange.getMin();
        innerMax = operatingATBR.zRange.getMax();
    }
    for (int i = outerMin; i <= outerMax; ++i) {
        for (int j = innerMin; j <= innerMax; ++j) {
            if (
                (greatestRange == COORDINATE_IDENTIFIER_Z && xyInRegion(i, j)) ||
                (greatestRange == COORDINATE_IDENTIFIER_Y && xzInRegion(i, j)) ||
                yzInRegion(i, j)
            ) {++hexCount;}
        }
    }
    return hexCount;
}

bool axisTranslationBoundedRegion::isEmpty () const {
    return xRange.isEmpty() ||
           ( !rangesOptimised &&
             (                     yRange.isEmpty() || zRange.isEmpty() ||
               aRange.isEmpty() || bRange.isEmpty() || cRange.isEmpty()
               )
             );
}

bool axisTranslationBoundedRegion::rangesAreOptimised () const {
    return rangesOptimised;
}

void axisTranslationBoundedRegion::optimiseRanges () {
    //
    rangesOptimised = true;
}

#ifndef AXIS_TRANSLATION_BOUNDED_REGION
    #define AXIS_TRANSLATION_BOUNDED_REGION

    #include "coords.h"
    #include "coordinate-range.h"

    class axisTranslationBoundedRegion {
        protected:
            coordinateRange xRange;
            coordinateRange yRange;
            coordinateRange zRange;
            coordinateRange aRange;
            coordinateRange bRange;
            coordinateRange cRange;
            bool rangesOptimised;
            mutable int hexCount;
            mutable bool hexCountIsFresh;
        public:
            axisTranslationBoundedRegion (
                coordinateRange const xr,
                coordinateRange const yr,
                coordinateRange const zr,
                coordinateRange const ar,
                coordinateRange const br,
                coordinateRange const cr
            );
            axisTranslationBoundedRegion (
                int const x1, int const x2,
                int const y1, int const y2,
                int const z1, int const z2,
                int const a1, int const a2,
                int const b1, int const b2,
                int const c1, int const c2
            );
            static axisTranslationBoundedRegion checked (
                int x1, int x2, int y1, int y2, int z1, int z2,
                int xa, int a2, int b1, int b2, int c1, int c2
            );
            axisTranslationBoundedRegion copyWithOptimisedRanges () const;
            bool xyInRegion (int const x, int const y) const;
            bool xzInRegion (int const x, int const z) const;
            bool yzInRegion (int const y, int const z) const;
            int numHexes () const;
            bool isEmpty () const;
            bool rangesAreOptimised () const;
            void optimiseRanges ();
    };
#endif

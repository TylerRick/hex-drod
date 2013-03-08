#ifndef COORDINATE_RANGE_H
    #define COORDINATE_RANGE_H

    #include <utility>

    class coordinateRange {
        protected:
            int minimum;
            int maximum;
        public:
            coordinateRange (int const rMin, int const rMax);
            static coordinateRange checked (int limit1, int limit2);
            bool inRange (int const value) const;
            int length () const;
            bool isEmpty () const;
            int getMin () const;
            int getMax () const;
            void setMin (int const newMin);
            void setMax (int const newMax);
            void setMinChecked (int const newMin);
            void setMaxChecked (int const newMax);
            void makeEmpty ();
            coordinateRange intersection (coordinateRange const that) const;
            coordinateRange unionHull (coordinateRange const that) const;
            void restrictXforYbyZ (int const y, coordinateRange const zRange);
            void restrictXforYbyA (int const y, coordinateRange const aRange);
            void restrictXforYbyB (int const y, coordinateRange const bRange);
            void restrictXforYbyC (int const y, coordinateRange const cRange);
            void restrictXforZbyY (int const z, coordinateRange const yRange);
            void restrictXforZbyA (int const z, coordinateRange const aRange);
            void restrictXforZbyB (int const z, coordinateRange const bRange);
            void restrictXforZbyC (int const z, coordinateRange const cRange);
            void restrictYforXbyZ (int const x, coordinateRange const zRange);
            void restrictYforXbyA (int const x, coordinateRange const aRange);
            void restrictYforXbyB (int const x, coordinateRange const bRange);
            void restrictYforXbyC (int const x, coordinateRange const cRange);
            void restrictYforZbyX (int const z, coordinateRange const xRange);
            void restrictYforZbyA (int const z, coordinateRange const aRange);
            void restrictYforZbyB (int const z, coordinateRange const bRange);
            void restrictYforZbyC (int const z, coordinateRange const cRange);
            void restrictZforXbyY (int const x, coordinateRange const yRange);
            void restrictZforXbyA (int const x, coordinateRange const aRange);
            void restrictZforXbyB (int const x, coordinateRange const bRange);
            void restrictZforXbyC (int const x, coordinateRange const cRange);
            void restrictZforYbyX (int const y, coordinateRange const xRange);
            void restrictZforYbyB (int const y, coordinateRange const aRange);
            void restrictZforYbyC (int const y, coordinateRange const bRange);
            void restrictZforYbyA (int const y, coordinateRange const cRange);
    };
#endif

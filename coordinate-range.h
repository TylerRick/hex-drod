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
    };
#endif

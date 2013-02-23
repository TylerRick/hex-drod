#ifndef HEX_COORDINATE_H
    #define HEX_COORDINATE_H

    class hexCoordinateSystem;

    class hexCoordinate {
        protected:
            int xCoord;
            int yCoord;
            hexCoordinateSystem const * coordinateSystem;
        public:
            hexCoordinate ();
                // Create a new hexCoordinate at the origin of the global
                // coordinate system.
            hexCoordinate (int const x, int const y);
                // Create a new hexCoordinate in the global coordinate system.
            hexCoordinate (hexCoordinateSystem const * const hcs);
                // Create a new hexCoordinate at the origin of the supplied
                // hexCoordinateSystem.
            hexCoordinate (int const x, int const y, hexCoordinateSystem const * const hcs);
                // Create a new hexCoordinate in the supplied
                // hexCoordinateSystem.
            hexCoordinateSystem const * getHexCoordinateSystem () const;
                // Get the hexCoordinateSystem of this hexCoordinate.
            bool coordinateSystemIsGlobal () const;
                // Determine whether this hexCoordinate is in the global
                // coordinate system.
            int getXCoord () const;
            int getYCoord () const;
            int getZCoord () const;
            int getACoord () const;
            int getBCoord () const;
            int getCCoord () const;
                // Get the indicated coordinate of this hex in its coordinate
                // system.
            int getGlobalXCoord () const;
            int getGlobalYCoord () const;
            int getGlobalZCoord () const;
            int getGlobalACoord () const;
            int getGlobalBCoord () const;
            int getGlobalCCoord () const;
                // Get the indicated coordinate of this hex in the global
                // coordinate system.
            int getXCoordIn (hexCoordinateSystem const hcs) const;
            int getYCoordIn (hexCoordinateSystem const hcs) const;
            int getZCoordIn (hexCoordinateSystem const hcs) const;
            int getACoordIn (hexCoordinateSystem const hcs) const;
            int getBCoordIn (hexCoordinateSystem const hcs) const;
            int getCCoordIn (hexCoordinateSystem const hcs) const;
                // Get the indicated coordinate of this hex in the supplied
                // hexCoordinateSystem.
            bool isDark () const;
                // Determine whether this hex is a dark hex.
            void setHexCoordinateSystem (hexCoordinateSystem const * const hcs);
            void setHexCoordinateSystemNaive (hexCoordinateSystem const * const hcs);
                // Set the hexCoordinateSystem of this hex. The first of these
                // methods changes the xCoord and yCoord data members so that
                // the same hex is represented after the change. The second,
                // "naive" method leaves xCoord and yCoord unchanged, thus
                // changing the hex to which the object refers (unless the new
                // hexCoordinateSystem happens to be the same as the old one).
            void setXCoord (int const x);
            void setYCoord (int const y);
                // Change the xCoord and yCoord data members.
            void moveToLocal (int const x, int const y);
            void moveToGlobal (int const x, int const y);
                // Move this hexCoordinate to the indicated local or global
                // (x, y)-coordinates, without changing its
                // hexCoordinateSystem.
            void moveTo (hexCoordinate const hc);
                // Move this hexCoordinate so that it represents the same hex
                // as the supplied hexCoordinate (but possibly not in the same
                // hexCoordinateSystem).
            void moveToNaive (hexCoordinate const hc);
                // Change this hexCoordinate so that its (x, y)-coordinates
                // are the same as the (x, y)-coordinates of the supplied
                // hexCoordinate. Note that only if the two hexCoordinates are
                // in the same hexCoordinateSystem will they represent the same
                // hex afterwards.
            void moveThrough (int const x, int const y);
                // Translates this hexCoordinate through (x, y).
            void moveThrough (hexCoordinate const hc);
                // Translates this hexCoordinate through the supplied
                // hexCoordinate. Warning: the hexCoordinateSystem of the
                // supplied hexCoordinate is accounted for, so only if the
                // supplied hexCoordinate is in the global coordinate system
                // is using this method equivalent to passing its xCoord
                // and yCoord (if they were public) to the other
                // moveThrough() method.
            void moveThroughNaive (hexCoordinate const hc);
                // Translates this hexCoordinate through the supplied
                // hexCoordinate. Unlike the previous method, the translation
                // is done "naively" (using only the xCoord and yCoord of the
                // supplied hexCoordinate); the hexCoordinateSystem of the
                // supplied hexCoordinate has no effect. In other words, this
                // method treats the supplied hexCoordinate as though it were
                // in the global coordinate system.
    };
#endif

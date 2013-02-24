#ifndef HEX_H
    #define HEX_H

    class hexCoordinateSystem;

    class hex {
        protected:
            int xCoord;
            int yCoord;
            hexCoordinateSystem const * coordinateSystem;
        public:
            hex ();
                // Create a new hex at the origin of the global coordinate system.
            hex (int const x, int const y);
                // Create a new hex in the global coordinate system.
            hex (hexCoordinateSystem const * const hcs);
                // Create a new hex at the origin of the supplied hexCoordinateSystem.
            hex (int const x, int const y, hexCoordinateSystem const * const hcs);
                // Create a new hex in the supplied hexCoordinateSystem.
            hexCoordinateSystem const * getCoordinateSystem () const;
                // Get the hexCoordinateSystem of this hex.
            bool coordinateSystemIsGlobal () const;
                // Determine whether this hex is in the global coordinate system.
            int getXCoord () const;
            int getYCoord () const;
            int getZCoord () const;
            int getACoord () const;
            int getBCoord () const;
            int getCCoord () const;
                // Get the indicated coordinate of this hex in its coordinate system.
            int getGlobalXCoord () const;
            int getGlobalYCoord () const;
            int getGlobalZCoord () const;
            int getGlobalACoord () const;
            int getGlobalBCoord () const;
            int getGlobalCCoord () const;
                // Get the indicated coordinate of this hex in the global coordinate
                // system.
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
            void setCoordinateSystem (hexCoordinateSystem const * const hcs);
            void setCoordinateSystemNaive (hexCoordinateSystem const * const hcs);
                // Set the hexCoordinateSystem of this hex. The first of these methods
                // changes the xCoord and yCoord data members so that the same hex is
                // represented after the change. The second, "naive" method leaves xCoord
                // and yCoord unchanged, thus changing the hex to which the object refers
                // (unless the new hexCoordinateSystem happens to be the same as the old
                // one).
            void setXCoord (int const x);
            void setYCoord (int const y);
                // Change the xCoord and yCoord data members.
            void moveToLocal (int const x, int const y);
            void moveToGlobal (int const x, int const y);
                // Move this hex to the indicated local or global (x, y)-coordinates,
                // without changing its hexCoordinateSystem.
            void moveTo (hex const hc);
                // Move this hex so that it represents the same hex as the supplied hex
                // (but possibly not in the same hexCoordinateSystem).
            void moveToNaive (hex const hc);
                // Change this hex so that its (x, y)-coordinates are the same as the
                // (x, y)-coordinates of the supplied hex. Note that only if the two
                // hexes are in the same hexCoordinateSystem will they represent the same
                // point afterwards.
            void moveThrough (int const x, int const y);
                // Translates this hex through (x, y).
            void moveThrough (hex const h);
                // Translates this hex through the global coordinates of the supplied
                // hex. Warning: the hexCoordinateSystem of the supplied hex is accounted
                // for, so only if the supplied hex is in the global coordinate system is
                // using this method equivalent to passing its xCoord and yCoord (if they
                // were public) to the other moveThrough() method.
            void moveThroughNaive (hex const h);
                // Translates this hex through the local coordinates of the supplied hex.
                // Unlike the previous method, the translation is done "naively" (using
                // only the xCoord and yCoord of the supplied hex); the
                // hexCoordinateSystem of the supplied hex has no effect. In other words,
                // this method treats the supplied hex as though it were in the global
                // coordinate system.
    };
#endif

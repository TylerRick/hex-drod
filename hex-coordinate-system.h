#ifndef HEX_COORDINATE_SYSTEM_H
    #define HEX_COORDINATE_SYSTEM_H

    #include "mathematics-functions.h"
    #include "hex-coordinate.h"

    class hexCoordinateSystem {
        protected:
            hexCoordinateSystem (int const x, int const y);
        public:
            static hexCoordinateSystem of (hexCoordinate const h);
                // Get a copy of the hexCoordinateSystem of the supplied
                // hexCoordinate.
            static hexCoordinateSystem fromOrigin (hexCoordinate const h);
                // Get the hexCoordinateSystem with the supplied hexCoordinate
                // as its origin.
            static hexCoordinateSystem fromOriginGlobal (int const x, int const y);
                // Get the hexCoordinateSystem with the supplied global
                // (x, y)-coordinates as its origin.
            hexCoordinateSystem fromOriginLocal (int const x, int const y) const;
                // Get the hexCoordinateSystem with the supplied local
                // (x, y)-coordinates as its origin.
            int const originX;
            int const originY;
                // The (x, y)-coordinates of the origin in this coordinate
                // system.
            int globalZCoordOfOrigin () const;
            int globalACoordOfOrigin () const;
            int globalBCoordOfOrigin () const;
            int globalCCoordOfOrigin () const;
                // Get the indicated coordinate in the global coordinate system
                // of the origin in this coordinate system.
            bool isGlobal () const;
                // Determines whether this is the global coordinate system,
                // that is to say, whether originX and originY are both 0.
            hexCoordinate localised (hexCoordinate const h) const;
                // Supply a hexCoordinate and get the equivalent hexCoordinate
                // in this coordinate system.
            hexCoordinate localHexCoordinateFromGlobal (int const x, int const y);
                // Supply global (x, y)-coordinates and get the equivalent
                // hexCoordinate in this coordinate system.
            hexCoordinate localHexCoordinateFromLocal (int const x, int const y);
                // Supply local (x, y)-coordinates and get the equivalent
                // hexCoordinate in this coordinate system.
            hexCoordinate globalHexCoordinateFromLocal (int const x, int const y);
                // Supply local (x, y)-coordinates and get the equivalent
                // hexCoordinate in the global coordinate system.
            int localXCoord (hexCoordinate const h) const;
            int localYCoord (hexCoordinate const h) const;
            int localZCoord (hexCoordinate const h) const;
            int localACoord (hexCoordinate const h) const;
            int localBCoord (hexCoordinate const h) const;
            int localCCoord (hexCoordinate const h) const;
                // Supply a hexCoordinate and get the indicated coordinate with
                // respect to this coordinate system.
            int globalXCoordFromLocal (int const x) const;
            int globalYCoordFromLocal (int const y) const;
            int globalZCoordFromLocal (int const x, int const y) const;
            int globalACoordFromLocal (int const x, int const y) const;
            int globalBCoordFromLocal (int const x, int const y) const;
            int globalCCoordFromLocal (int const x, int const y) const;
                // Supply local (x, y)-coordinates and get the indicated
                // global coordinate.
            int localXCoordFromGlobal (int const x) const;
            int localYCoordFromGlobal (int const y) const;
            int localZCoordFromGlobal (int const x, int const y) const;
            int localACoordFromGlobal (int const x, int const y) const;
            int localBCoordFromGlobal (int const x, int const y) const;
            int localCCoordFromGlobal (int const x, int const y) const;
                // Supply global (x, y)-coordinates in the global coordinate
                // system and get the indicated local coordinate.
            bool isDarkHexFromA (int const a) const;
            bool isDarkHexFromXY (int const x, int const y) const;
                // Determine whether a hex should be a dark hex by supplying
                // its local a-coordinate or local (x, y)-coordinates.
    };

    extern hexCoordinateSystem const globalHexCoordinateSystem;
        // This is global in both senses of the word. It is the
        // hexCoordinateSystem whose xOffset and yOffset are both 0, and it
        // is also global in the sense that it is a global variable.
#endif

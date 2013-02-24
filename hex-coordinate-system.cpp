#include "hex-coordinate-system.h"

hexCoordinateSystem::hexCoordinateSystem (int const x, int const y):
    originX(x), originY(y) {}

hexCoordinateSystem hexCoordinateSystem::of (hex const h) {
    return *(h.getCoordinateSystem());
}

hexCoordinateSystem hexCoordinateSystem::fromOrigin (hex const h) {
    return hexCoordinateSystem(h.getGlobalXCoord(), h.getGlobalYCoord());
}

hexCoordinateSystem hexCoordinateSystem::fromOriginGlobal (int const x, int const y) {
    return hexCoordinateSystem(x, y);
}

hexCoordinateSystem hexCoordinateSystem::fromOriginLocal (int const x, int const y) const {
    return hexCoordinateSystem(x + originX, y + originY);
}

int hexCoordinateSystem::globalZCoordOfOrigin () const {
    return globalZCoordFromLocal(0, 0);
}

int hexCoordinateSystem::globalACoordOfOrigin () const {
    return globalACoordFromLocal(0, 0);
}

int hexCoordinateSystem::globalBCoordOfOrigin () const {
    return globalBCoordFromLocal(0, 0);
}

int hexCoordinateSystem::globalCCoordOfOrigin () const {
    return globalCCoordFromLocal(0, 0);
}

bool hexCoordinateSystem::isGlobal () const {
    return originX == 0 && originY == 0;
}

hex hexCoordinateSystem::localised (hex const h) const {
    return hex (h.getGlobalXCoord() - originX, h.getGlobalYCoord() - originY, this);
}

hex hexCoordinateSystem::localHexFromGlobal (int const x, int const y) {
    return hex(x - originX, y - originY, this);
}

hex hexCoordinateSystem::localHexFromLocal (int const x, int const y) {
    return hex(x, y, this);
}

hex hexCoordinateSystem::globalHexFromLocal (int const x, int const y) {
    return hex(x + originX, y + originY, &globalHexCoordinateSystem);
}

int hexCoordinateSystem::localXCoord (hex const h) const {
    return h.getGlobalXCoord() - originX;
}

int hexCoordinateSystem::localYCoord (hex const h) const {
    return h.getGlobalYCoord() - originY;
}

int hexCoordinateSystem::localZCoord (hex const h) const {
    return zCoord(localXCoord(h), localYCoord(h));
}

int hexCoordinateSystem::localACoord (hex const h) const {
    return aCoord(localXCoord(h), localYCoord(h));
}

int hexCoordinateSystem::localBCoord (hex const h) const {
    return bCoord(localXCoord(h), localYCoord(h));
}

int hexCoordinateSystem::localCCoord (hex const h) const {
    return cCoord(localXCoord(h), localYCoord(h));
}

int hexCoordinateSystem::globalXCoordFromLocal (int const x) const {
    return x + originX;
}

int hexCoordinateSystem::globalYCoordFromLocal (int const y) const {
    return y + originY;
}

int hexCoordinateSystem::globalZCoordFromLocal (int const x, int const y) const {
    return zCoord(globalXCoordFromLocal(x), globalYCoordFromLocal(y));
}

int hexCoordinateSystem::globalACoordFromLocal (int const x, int const y) const {
    return aCoord(globalXCoordFromLocal(x), globalYCoordFromLocal(y));
}

int hexCoordinateSystem::globalBCoordFromLocal (int const x, int const y) const {
    return bCoord(globalXCoordFromLocal(x), globalYCoordFromLocal(y));
}

int hexCoordinateSystem::globalCCoordFromLocal (int const x, int const y) const {
    return cCoord(globalXCoordFromLocal(x), globalYCoordFromLocal(y));
}

int hexCoordinateSystem::localXCoordFromGlobal (int const x) const {
    return x - originX;
}

int hexCoordinateSystem::localYCoordFromGlobal (int const y) const {
    return y - originY;
}

int hexCoordinateSystem::localZCoordFromGlobal (int const x, int const y) const {
    return zCoord(localXCoordFromGlobal(x), localYCoordFromGlobal(y));
}

int hexCoordinateSystem::localACoordFromGlobal (int const x, int const y) const {
    return aCoord(localXCoordFromGlobal(x), localYCoordFromGlobal(y));
}

int hexCoordinateSystem::localBCoordFromGlobal (int const x, int const y) const {
    return bCoord(localXCoordFromGlobal(x), localYCoordFromGlobal(y));
}

int hexCoordinateSystem::localCCoordFromGlobal (int const x, int const y) const {
    return cCoord(localXCoordFromGlobal(x), localYCoordFromGlobal(y));
}

bool hexCoordinateSystem::isDarkHexFromA (int const a) const {
    return darkHex(a + globalACoordOfOrigin());
}

bool hexCoordinateSystem::isDarkHexFromXY (int const x, int const y) const {
    return darkHex(globalACoordFromLocal(x, y));
}

hexCoordinateSystem const globalHexCoordinateSystem =
    hexCoordinateSystem::fromOriginGlobal(0, 0);

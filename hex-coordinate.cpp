#include "hex-coordinate-system.h"

hexCoordinate::hexCoordinate ():
    xCoord(0), yCoord(0), coordinateSystem(&globalHexCoordinateSystem) {}

hexCoordinate::hexCoordinate (int const x, int const y):
    xCoord(x), yCoord(y), coordinateSystem(&globalHexCoordinateSystem) {}

hexCoordinate::hexCoordinate (hexCoordinateSystem const * const hcs):
    xCoord(0), yCoord(0), coordinateSystem(hcs) {}

hexCoordinate::hexCoordinate
    (int const x, int const y, hexCoordinateSystem const * const hcs):
    xCoord(x), yCoord(y), coordinateSystem(hcs) {}

hexCoordinateSystem const * hexCoordinate::getHexCoordinateSystem () const {
    return coordinateSystem;
}

bool hexCoordinate::coordinateSystemIsGlobal () const {
    return coordinateSystem->isGlobal();
}

int hexCoordinate::getXCoord () const {
    return xCoord;
}

int hexCoordinate::getYCoord () const {
    return yCoord;
}

int hexCoordinate::getZCoord () const {
    return zCoord(xCoord, yCoord);
}

int hexCoordinate::getACoord () const {
    return aCoord(xCoord, yCoord);
}

int hexCoordinate::getBCoord () const {
    return bCoord(xCoord, yCoord);
}

int hexCoordinate::getCCoord () const {
    return cCoord(xCoord, yCoord);
}

int hexCoordinate::getGlobalXCoord () const {
    return coordinateSystem->globalXCoordFromLocal(xCoord);
}

int hexCoordinate::getGlobalYCoord () const {
    return coordinateSystem->globalYCoordFromLocal(yCoord);
}

int hexCoordinate::getGlobalZCoord () const {
    return zCoord(getGlobalXCoord(), getGlobalYCoord());
}

int hexCoordinate::getGlobalACoord () const {
    return aCoord(getGlobalXCoord(), getGlobalYCoord());
}

int hexCoordinate::getGlobalBCoord () const {
    return bCoord(getGlobalXCoord(), getGlobalYCoord());
}

int hexCoordinate::getGlobalCCoord () const {
    return cCoord(getGlobalXCoord(), getGlobalYCoord());
}

int hexCoordinate::getXCoordIn (hexCoordinateSystem const hcs) const {
    return hcs.localXCoordFromGlobal(getGlobalXCoord());
}

int hexCoordinate::getYCoordIn (hexCoordinateSystem const hcs) const {
    return hcs.localYCoordFromGlobal(getGlobalYCoord());
}

int hexCoordinate::getZCoordIn (hexCoordinateSystem const hcs) const {
    return zCoord(getXCoordIn(hcs), getYCoordIn(hcs));
}

int hexCoordinate::getACoordIn (hexCoordinateSystem const hcs) const {
    return aCoord(getXCoordIn(hcs), getYCoordIn(hcs));
}

int hexCoordinate::getBCoordIn (hexCoordinateSystem const hcs) const {
    return bCoord(getXCoordIn(hcs), getYCoordIn(hcs));
}

int hexCoordinate::getCCoordIn (hexCoordinateSystem const hcs) const {
    return cCoord(getXCoordIn(hcs), getYCoordIn(hcs));
}

bool hexCoordinate::isDark () const {
    return darkHex(getGlobalACoord());
}

void hexCoordinate::setHexCoordinateSystem (hexCoordinateSystem const * const hcs) {
    xCoord = getXCoordIn(*hcs);
    yCoord = getYCoordIn(*hcs);
    setHexCoordinateSystemNaive(hcs);
}

void hexCoordinate::setHexCoordinateSystemNaive (hexCoordinateSystem const * const hcs) {
    coordinateSystem = hcs;
}

void hexCoordinate::setXCoord (int const x) {
    xCoord = x;
}

void hexCoordinate::setYCoord (int const y) {
    yCoord = y;
}

void hexCoordinate::moveToLocal (int const x, int const y) {
    setXCoord(x);
    setYCoord(y);
}

void hexCoordinate::moveToGlobal (int const x, int const y) {
    setXCoord(coordinateSystem->localXCoordFromGlobal(x));
    setYCoord(coordinateSystem->localYCoordFromGlobal(y));
}

void hexCoordinate::moveTo (hexCoordinate const hc) {
    setXCoord(hc.getXCoordIn(*coordinateSystem));
    setYCoord(hc.getYCoordIn(*coordinateSystem));
}

void hexCoordinate::moveToNaive (hexCoordinate const hc) {
    setXCoord(hc.xCoord);
    setYCoord(hc.yCoord);
}

void hexCoordinate::moveThrough (int const x, int const y) {
    setXCoord(xCoord + x);
    setYCoord(yCoord + y);
}

void hexCoordinate::moveThrough (hexCoordinate const hc) {
    setXCoord(xCoord + hc.getGlobalXCoord());
    setYCoord(yCoord + hc.getGlobalYCoord());
}

void hexCoordinate::moveThroughNaive (hexCoordinate const hc) {
    setXCoord(xCoord + hc.xCoord);
    setYCoord(yCoord + hc.yCoord);
}

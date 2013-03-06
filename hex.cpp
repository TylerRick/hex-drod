#include "hex-coordinate-system.h"

hex::hex ():
    xCoord(0), yCoord(0), coordinateSystem(&globalHexCoordinateSystem) {}

hex::hex (int const x, int const y):
    xCoord(x), yCoord(y), coordinateSystem(&globalHexCoordinateSystem) {}

hex::hex (hexCoordinateSystem const * const hcs):
    xCoord(0), yCoord(0), coordinateSystem(hcs) {}

hex::hex (int const x, int const y, hexCoordinateSystem const * const hcs):
    xCoord(x), yCoord(y), coordinateSystem(hcs) {}

hexCoordinateSystem const * hex::getCoordinateSystem () const {
    return coordinateSystem;
}

bool hex::coordinateSystemIsGlobal () const {
    return coordinateSystem->isGlobal();
}

int hex::getXCoord () const {
    return xCoord;
}

int hex::getYCoord () const {
    return yCoord;
}

int hex::getZCoord () const {
    return coords::xytoz(xCoord, yCoord);
}

int hex::getACoord () const {
    return coords::xytoa(xCoord, yCoord);
}

int hex::getBCoord () const {
    return coords::xytob(xCoord, yCoord);
}

int hex::getCCoord () const {
    return coords::xytoc(xCoord, yCoord);
}

int hex::getGlobalXCoord () const {
    return coordinateSystem->globalXCoordFromLocal(xCoord);
}

int hex::getGlobalYCoord () const {
    return coordinateSystem->globalYCoordFromLocal(yCoord);
}

int hex::getGlobalZCoord () const {
    return coords::xytoz(getGlobalXCoord(), getGlobalYCoord());
}

int hex::getGlobalACoord () const {
    return coords::xytoa(getGlobalXCoord(), getGlobalYCoord());
}

int hex::getGlobalBCoord () const {
    return coords::xytob(getGlobalXCoord(), getGlobalYCoord());
}

int hex::getGlobalCCoord () const {
    return coords::xytoc(getGlobalXCoord(), getGlobalYCoord());
}

int hex::getXCoordIn (hexCoordinateSystem const hcs) const {
    return hcs.localXCoordFromGlobal(getGlobalXCoord());
}

int hex::getYCoordIn (hexCoordinateSystem const hcs) const {
    return hcs.localYCoordFromGlobal(getGlobalYCoord());
}

int hex::getZCoordIn (hexCoordinateSystem const hcs) const {
    return coords::xytoz(getXCoordIn(hcs), getYCoordIn(hcs));
}

int hex::getACoordIn (hexCoordinateSystem const hcs) const {
    return coords::xytoa(getXCoordIn(hcs), getYCoordIn(hcs));
}

int hex::getBCoordIn (hexCoordinateSystem const hcs) const {
    return coords::xytob(getXCoordIn(hcs), getYCoordIn(hcs));
}

int hex::getCCoordIn (hexCoordinateSystem const hcs) const {
    return coords::xytoc(getXCoordIn(hcs), getYCoordIn(hcs));
}

bool hex::isDark () const {
    return coords::darkHex(getGlobalACoord());
}

void hex::setCoordinateSystem (hexCoordinateSystem const * const hcs) {
    xCoord = getXCoordIn(*hcs);
    yCoord = getYCoordIn(*hcs);
    setCoordinateSystemNaive(hcs);
}

void hex::setCoordinateSystemNaive (hexCoordinateSystem const * const hcs) {
    coordinateSystem = hcs;
}

void hex::setXCoord (int const x) {
    xCoord = x;
}

void hex::setYCoord (int const y) {
    yCoord = y;
}

void hex::moveToLocal (int const x, int const y) {
    setXCoord(x);
    setYCoord(y);
}

void hex::moveToGlobal (int const x, int const y) {
    setXCoord(coordinateSystem->localXCoordFromGlobal(x));
    setYCoord(coordinateSystem->localYCoordFromGlobal(y));
}

void hex::moveTo (hex const h) {
    setXCoord(h.getXCoordIn(*coordinateSystem));
    setYCoord(h.getYCoordIn(*coordinateSystem));
}

void hex::moveToNaive (hex const h) {
    setXCoord(h.xCoord);
    setYCoord(h.yCoord);
}

void hex::moveThrough (int const x, int const y) {
    setXCoord(xCoord + x);
    setYCoord(yCoord + y);
}

void hex::moveThrough (hex const h) {
    setXCoord(xCoord + h.getGlobalXCoord());
    setYCoord(yCoord + h.getGlobalYCoord());
}

void hex::moveThroughNaive (hex const h) {
    setXCoord(xCoord + h.xCoord);
    setYCoord(yCoord + h.yCoord);
}

#include "coordinate-range.h"

coordinateRange::coordinateRange (int const rMin, int const rMax):
    minimum(rMin), maximum(rMax) {};

coordinateRange coordinateRange::checked (int limit1, int limit2) {
    if (limit1 > limit2) {
        std::swap(limit1, limit2);
    }
    return coordinateRange(limit1, limit2);
}

bool coordinateRange::inRange (int const value) const {
    return value >= minimum && value <= maximum;
}

int coordinateRange::length () const {
    return maximum - minimum;
}

bool coordinateRange::isEmpty () const {
    return minimum > maximum;
}

int coordinateRange::getMin () const {
    return minimum;
}

int coordinateRange::getMax () const {
    return maximum;
}

void coordinateRange::setMin (int const newMin) {
    minimum = newMin;
}

void coordinateRange::setMax (int const newMax) {
    maximum = newMax;
}

void coordinateRange::setMinChecked (int const newMin) {
    if (newMin > maximum) {
        maximum = newMin;
    }
    minimum = newMin;
}

void coordinateRange::setMaxChecked (int const newMax) {
    if (newMax < minimum) {
        minimum = newMax;
    }
    maximum = newMax;
}

void coordinateRange::makeEmpty () {
    maximum = 0;
    minimum = 1;
}

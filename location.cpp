#include "location.h"

Location::Location(int x, int y) {
    this->x = x;
    this->y = y;
}

Location & Location::operator = (Location & loc) {
    this->x = loc.x;
    this->y = loc.y;
    return *this;
}

bool Location::operator == (Location & loc) {
    return (this->x == loc.x && this->y == loc.y)? true : false;
}

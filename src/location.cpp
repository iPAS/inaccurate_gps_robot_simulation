#include "location.h"

Location::Location(int x, int y) {
    this->x = x;
    this->y = y;
}

Location & Location::operator = (const Location & loc) {
    this->x = loc.x;
    this->y = loc.y;
    return *this;
}

Location & Location::operator += (const Location & loc) {
    this->x += loc.x;
    this->y += loc.y;
    return *this;
}

bool Location::operator == (const Location & loc) {
    return (this->x == loc.x && this->y == loc.y)? true : false;
}

Location::operator char *(void) {
    static char str[20];
    snprintf(str, sizeof str, "(%d, %d)", x, y);
    return str;
}

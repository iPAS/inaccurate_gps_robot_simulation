#pragma once

#include <iostream>
using namespace std;

class Location {
    private:
        int x;
        int y;

    public:
        Location() {};
        Location(int, int);

        Location & operator = (Location &);
        Location & operator += (Location &);
        bool operator == (Location &);

        int get_x(void) { return this->x; };
        int get_y(void) { return this->y; };
};

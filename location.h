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

        Location & operator = (const Location &);
        Location & operator += (const Location &);
        bool operator == (const Location &);

        int get_x(void) { return this->x; };
        int get_y(void) { return this->y; };
};

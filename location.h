#pragma once

#include <iostream>
using namespace std;

class Location {
    private:
        int x;
        int y;

    public:
        Location() {};
        Location(int x, int y);

        Location & operator = (Location &);
        bool operator == (Location &);
};

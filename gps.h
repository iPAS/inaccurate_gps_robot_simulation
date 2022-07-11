#pragma once

#include "location.h"

#include <iostream>
using namespace std;

class GPS {
    protected:
        Location location;
        Location disturbance;

        int random_range(int);

    public:
        GPS(Location &);

        Location & get_location(void);
        Location & set_location_relatively(Location &);        

        void set_disturbance(int, int);
};

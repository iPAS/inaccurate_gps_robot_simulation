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
        GPS();
        GPS(Location &);

        const Location & get_location(void);
        const Location & set_location_relatively(const Location &);        

        void set_disturbance(int, int);
};

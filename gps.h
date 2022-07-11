#pragma once

#include "location.h"

#include <iostream>
using namespace std;

class GPS {
    protected:
        Location location;
    
    public:
        GPS(Location &);

        Location & get_location(void);
        Location & set_location_relatively(Location &);
};

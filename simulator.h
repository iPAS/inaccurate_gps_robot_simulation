#pragma once

#include "location.h"
#include "robot.h"

#include <iostream>
using namespace std;

#define MINIMUM_ACCEPTANCE 3.

class Simulator {
    private:
        Robot *robot;
        location_set_t targets;

    public:
        Simulator(Robot &, location_set_t &);
        void run(void);    
};

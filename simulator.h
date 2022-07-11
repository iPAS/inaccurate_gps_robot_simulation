#pragma once

#include "location.h"
#include "robot.h"

#include <iostream>
#include <queue>
using namespace std;

typedef queue<Location> location_set_t;

#define MINIMUM_ACCEPTANCE 3.

class Simulator {
    private:
        Robot *robot;
        location_set_t targets;

    public:
        Simulator(Robot &, location_set_t &);
        int run(void);
};

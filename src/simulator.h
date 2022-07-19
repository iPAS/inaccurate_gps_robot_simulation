#pragma once

#include "location.h"
#include "robot.h"

#include <iostream>
#include <queue>
using namespace std;

typedef queue<Location> location_set_t;

class Simulator {
    private:
        Robot *robot;
        location_set_t targets;
        int max_step_to_target;

    public:
        Simulator(Robot &, location_set_t &, int max_step_to_target = 20);
        int run(void);
};

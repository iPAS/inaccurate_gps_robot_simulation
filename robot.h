#pragma once

#include "gps.h"

#include <iostream>
#include <vector>

using namespace std;

typedef enum {
    GO_NORTH,
    GO_EAST,
    GO_SOUTH,
    GO_WEST
} command_t;

typedef vector<Location> location_set_t;

class Robot {
    private:
        GPS gps;
        int step_size;

        location_set_t points;

    public:
        Robot(Location &, int stop_size = 1);

        bool is_job_done(void);
        command_t generate_command(void);
        void execute_command(command_t);
        float measure_error(void);
        void next_target(void);
};

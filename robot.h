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

class Robot {
    private:
        GPS gps;
        int step_size;

        vector<Location> set_points;

    public:
        Robot(Location &, int);

        bool is_job_done(void);
        command_t process_generating_command(void);
        void execute_command(command_t);
        int measure_error(void);
};

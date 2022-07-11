#pragma once

#include "gps.h"

#include <iostream>
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
        Location target;

    public:
        Robot(Location &, int stop_size = 1);

        command_t generate_command(void);
        void execute_command(command_t);
        float measure_error(void);
        void set_target(const Location &);

        void report(void);
};

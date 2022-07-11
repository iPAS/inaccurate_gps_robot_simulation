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

    public:
        Robot(Location &, int);

        void do_command(command_t);
};

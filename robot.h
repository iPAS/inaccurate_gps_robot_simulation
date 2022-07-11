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
        int max_step_size;
        Location target;
        Location location;
        float max_accepted_err;

    public:
        GPS gps;

        Robot(Location &, int max_step_size = 5, float max_err = 10.);

        command_t generate_command(int & param);
        void execute_command(command_t, int);
        float measure_error(void);
        void set_target(const Location &);
        
        bool operate(void);
        void report(void);
};

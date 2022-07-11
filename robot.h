#pragma once

#include "gps.h"

#include <iostream>
using namespace std;

typedef enum {
    GO_NORTH = 0,
    GO_EAST,
    GO_SOUTH,
    GO_WEST,
    NONE
} command_t;

class Robot {
    private:
        int max_step_size;
        Location target;
        Location location;
        float max_accepted_err;
        command_t latest_cmd;
        int latest_param;

    public:
        GPS gps;

        Robot(Location &, int max_step_size = 5, float max_err = 10.);

        command_t generate_command(int & param);
        void execute_command(command_t, int);
        float measure_error(void);
        void set_target(const Location &);
        
        bool operate(void);
        void report(int no = 0);
};

#include "robot.h"

Robot::Robot(Location &init_loc, int step_size = 1) : gps(init_loc) {
    this->step_size = step_size;
}

bool Robot::is_job_done(void) {
    return true;
}

command_t Robot::process_generating_command(void) {
    return GO_NORTH;
}

void Robot::execute_command(command_t cmd) {
    switch (cmd) {
    case GO_NORTH:
        break;
    case GO_EAST:
        break;
    case GO_SOUTH:
        break;
    case GO_WEST:
        break;
    };
}

int Robot::measure_error(void) {
    return 0;
}

#include "robot.h"

Robot::Robot(Location &init_loc, int step_size = 1) : gps(init_loc) {
    this->step_size = step_size;
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

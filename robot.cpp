#include "robot.h"

Robot::Robot(Location &init_loc, int step_size) : gps(init_loc) {
    this->step_size = step_size;
}

bool Robot::is_job_done(void) {
    return true;
}

command_t Robot::generate_command(void) {
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

float Robot::measure_error(void) {
    return 0;
}

void Robot::next_target(void) {

}

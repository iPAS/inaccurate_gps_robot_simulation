#include <math.h>
#include "robot.h"

Robot::Robot(Location &init_loc, int step_size, float max_err) : gps(init_loc) {
    this->step_size = step_size;
    this->location = init_loc;
    this->max_accepted_err = max_err;
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

inline float Robot::measure_error(void) {
    float err_x = this->target.get_x() - this->location.get_x();
    float err_y = this->target.get_y() - this->location.get_y();
    return sqrt(err_x*err_x + err_y*err_y);
}

void Robot::set_target(const Location & target) {
    this->target = target;
}

int Robot::operate(void) {

    // command_t cmd = this->robot->generate_command();
    // this->robot->execute_command(cmd);
    
    return 0;
}

void Robot::report(void) {
    printf("Target:(%d, %d) ", this->target.get_x(), this->target.get_y());
    printf("Loc:(%d, %d) ", this->location.get_x(), this->location.get_y());
    printf("Err:%f\n", this->measure_error());
}

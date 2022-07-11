#include <math.h>
#include "robot.h"

Robot::Robot(Location &init_loc, int max_step_size, float max_err) : gps(init_loc) {
    this->max_step_size = max_step_size;
    this->location = init_loc;
    this->max_accepted_err = max_err;
    this->latest_cmd = NONE;
    this->latest_param = 0;
}

void Robot::set_target(const Location & target) {
    this->target = target;
    cout << "Target:" << this->target << endl; 
}

inline float Robot::measure_error(void) {
    int err_x = this->target.get_x() - this->location.get_x();
    int err_y = this->target.get_y() - this->location.get_y();
    return sqrt(err_x*err_x + err_y*err_y);
}

command_t Robot::generate_command(int & param) {
    this->location = gps.get_location();  // Drift in here
    int err_x = this->target.get_x() - this->location.get_x();
    int err_y = this->target.get_y() - this->location.get_y();

    if (abs(err_x) > abs(err_y)) {
        param = abs(err_x);
        if (param > this->max_step_size)
            param = this->max_step_size;
        return (err_x > 0)? GO_EAST : GO_WEST;
    } else {
        param = abs(err_y);
        if (param > this->max_step_size)
            param = this->max_step_size;
        return (err_y > 0)? GO_NORTH : GO_SOUTH;
    }
}

void Robot::execute_command(command_t cmd, int param = 1) {
    // Moving
    switch (cmd) {  
        case GO_NORTH:
            this->gps.set_location_relatively(Location(0, param));
            break;
        case GO_EAST:
            this->gps.set_location_relatively(Location(param, 0));
            break;
        case GO_SOUTH:
            this->gps.set_location_relatively(Location(0, -param));
            break;
        case GO_WEST:
            this->gps.set_location_relatively(Location(-param, 0));
            break;
        default:
            break;
    };
}

bool Robot::operate(void) {
    int param;
    command_t cmd = this->generate_command(param);

    this->latest_cmd = cmd;
    this->latest_param = param;

    this->execute_command(cmd, param);

    return (this->measure_error() < this->max_accepted_err)? true : false;
}

void Robot::report(void) {
    printf("Target:%s ", (char *)this->target);
    printf("Loc:%s ", (char *)this->location);
    printf("Err:%.2f ", this->measure_error());

    const char * cmd_in_str[] = {
        "N", "E", "S", "W", "_"
    };
    printf("LstCmd:%s ", cmd_in_str[this->latest_cmd]);
    printf("LstParam:%d \n", this->latest_param);
}

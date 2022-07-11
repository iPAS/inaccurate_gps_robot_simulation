#include "simulator.h"

Simulator::Simulator(Robot & robot, location_set_t & target_location_set) {
    this->robot = &robot;
    this->targets = target_location_set;
}

int Simulator::run(void) {
    while (true) {
        if (this->robot->measure_error() < MINIMUM_ACCEPTANCE) {
            if (this->targets.size() == 0)
                break;

            this->robot->set_target(this->targets.front());
            this->targets.pop();
        }
        command_t cmd = this->robot->generate_command();
        this->robot->execute_command(cmd);
        this->robot->report();
    }

    return 0;  // Success
}

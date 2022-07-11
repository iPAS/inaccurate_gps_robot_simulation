#include "simulator.h"

Simulator::Simulator(Robot & robot, location_set_t & target_location_set) {
    this->robot = &robot;
    this->targets = target_location_set;
}

void Simulator::run(void) {
    while (this-robot->is_job_done() == false) {
        if (this->robot->measure_error() < MINIMUM_ACCEPTANCE) {
            this->robot->next_target();
            // TODO: print milestone
        }
        command_t cmd = this->robot->generate_command();
        // TODO: print cmd here
        this->robot->execute_command(cmd);
        // TODO: print current location
    }
    // TODO: print job done
}

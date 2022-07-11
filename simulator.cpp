#include "simulator.h"

Simulator::Simulator(Robot & robot, location_set_t & target_location_set, int max_step_to_target) {
    this->robot = &robot;
    this->targets = target_location_set;
    this->max_step_to_target = max_step_to_target;
}

int Simulator::run(void) {
    do {
        this->robot->set_target(this->targets.front());
        this->targets.pop();

        int rc;
        int step = this->max_step_to_target;
        for (; step > 0; step--) {
            this->robot->report();
            rc = this->robot->operate();        
            if (rc == 0)
                break;
        }
    } while (this->targets.size() > 0);

    return 0;  // Success
}

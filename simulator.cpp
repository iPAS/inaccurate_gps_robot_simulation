#include "simulator.h"

Simulator::Simulator(Robot & robot, location_set_t & target_location_set) {
    this->robot = &robot;
    this->targets = target_location_set;
}

int Simulator::run(void) {
    int max_step = 10;
    do {
        this->robot->set_target(this->targets.front());
        this->targets.pop();

        int rc;
        for (; max_step > 0; max_step--) {
            this->robot->report();
            rc = this->robot->operate();        
            if (rc == 0)
                break;
        }
    } while (this->targets.size() > 0);

    return 0;  // Success
}

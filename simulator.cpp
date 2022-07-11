#include "simulator.h"

Simulator::Simulator(Robot & robot, location_set_t & target_location_set, int max_step_to_target) {
    this->robot = &robot;
    this->targets = target_location_set;
    this->max_step_to_target = max_step_to_target;
}

int Simulator::run(void) {
    this->robot->report();
    do {
        cout << "---" << endl;
        this->robot->set_target(this->targets.front());
        this->targets.pop();
        
        for (int step = this->max_step_to_target; step > 0; step--) {
            if (this->robot->operate() == true) {
                this->robot->report();
                break;
            }
            this->robot->report();
        }
    } while (this->targets.size() > 0);

    return 0;  // Success
}

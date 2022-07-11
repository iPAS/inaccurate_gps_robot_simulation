#include "simulator.h"

Simulator::Simulator(Robot & robot, location_set_t & target_location_set, int max_step_to_target) {
    this->robot = &robot;
    this->targets = target_location_set;
    this->max_step_to_target = max_step_to_target;
}

int Simulator::run(void) {
    this->robot->report();
    do {
        cout << "----------" << endl;
        this->robot->set_target(this->targets.front());
        cout << endl;
        this->targets.pop();
        
        for (int i = 1; i <= this->max_step_to_target; i++) {
            if (this->robot->operate() == true) {
                this->robot->report(i);
                break;
            }
            this->robot->report(i);
        }
    } while (this->targets.size() > 0);

    return 0;  // Success
}

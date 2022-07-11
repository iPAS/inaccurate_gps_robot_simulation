#include "simulator.h"

int main() {
    // Setup location of the robot
    Location start_loc(0, 0);
    Robot robot(start_loc);

    // Setup the destination points
    location_set_t target_location_set;
    target_location_set.push(Location(10, 10));
    target_location_set.push(Location(100, 100));
    Simulator sim(robot, target_location_set);

    // Start the simulator
    return sim.run();
}

#include "simulator.h"

int main() {
    const int STEP_SIZE = 1;
    const float MAX_ERR = 10.;
    const int MAX_STEP_TO_TARGET = 20;

    // Setup location of the robot
    Location start_loc(0, 0);
    Robot robot(start_loc, STEP_SIZE, MAX_ERR);
    robot.gps.set_disturbance(10, 10);  // Inaccuracy of the GPS

    // Setup the destination points
    location_set_t target_location_set;
    target_location_set.push(Location(10, 10));
    target_location_set.push(Location(100, 100));
    Simulator sim(robot, target_location_set, MAX_STEP_TO_TARGET);

    // Start the simulator
    return sim.run();
}

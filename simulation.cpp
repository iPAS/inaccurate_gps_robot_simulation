#include "simulator.h"

int main() {
    const float MAX_ERR = 10.;
    const int MAX_STEP_SIZE = 10;
    const int MAX_STEP_TO_TARGET = 30;

    // Setup location of the robot
    Location start_loc(0, 0);
    Robot robot(start_loc, MAX_STEP_SIZE, MAX_ERR);
    robot.gps.set_disturbance(10, 10);  // Inaccuracy of the GPS

    // Setup the destination points
    location_set_t target_location_set;
    target_location_set.push(Location(10, 10));
    target_location_set.push(Location(-50, 60));
    target_location_set.push(Location(-20, -30));
    target_location_set.push(Location(20, -10));
    Simulator sim(robot, target_location_set, MAX_STEP_TO_TARGET);

    // Start the simulator
    return sim.run();
}

#include "simulator.h"

int main() {
    Location start_loc(0, 0);
    Robot robot(start_loc);

    location_set_t target_location_set;
    target_location_set.push_back(Location(10, 10));
    target_location_set.push_back(Location(100, 100));
    Simulator sim(robot, target_location_set);

    sim.run();
    return 0;
}

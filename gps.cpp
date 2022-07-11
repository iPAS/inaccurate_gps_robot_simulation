#include "gps.h"

GPS::GPS() : disturbance(0, 0) {
    this->location = Location(0, 0);
}

GPS::GPS(Location & loc) : disturbance(0, 0) {
    this->location = loc;
}

inline int GPS::random_range(int range) {
    return (range == 0)? 0 : (rand() % (range * 2)) - range;
}

Location & GPS::get_location() {
    Location drift(this->random_range( this->disturbance.get_x() ), 
                   this->random_range( this->disturbance.get_y() ));
    cout << "Drift:" << (char *)drift << endl;
    this->location += drift;
    return this->location;
}

Location & GPS::set_location_relatively(const Location & loc) {
    cout << "Go:" << (char *)((Location)loc) << endl;
    return this->location += loc;
}

void GPS::set_disturbance(int x, int y) {
    this->disturbance = Location(x, y);
}

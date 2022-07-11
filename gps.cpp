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

const Location & GPS::get_location() {
    Location drift(this->random_range( this->disturbance.get_x() ), 
                   this->random_range( this->disturbance.get_y() ));
    cout << ">> GPS Drift:" << drift << endl;
    this->location += drift;
    return this->location;
}

const Location & GPS::set_location_relatively(const Location & loc) {
    return this->location += loc;
}

void GPS::set_disturbance(int x, int y) {
    this->disturbance = Location(x, y);
}

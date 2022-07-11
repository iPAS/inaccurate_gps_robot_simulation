#include "gps.h"

GPS::GPS(Location & loc) {
    this->location = loc;
}

Location & GPS::get_location() {
    return this->location;
}

Location & GPS::set_location_relatively(Location & loc) {
    return this->location = loc;
}

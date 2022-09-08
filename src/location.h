#pragma once

#include <iostream>
using namespace std;

class Location {
  private:
    int x;
    int y;

  public:
    Location() : Location(0, 0) {};
    Location(int, int);

    Location & operator = (const Location &);
    Location & operator += (const Location &);
    bool operator == (const Location &);
    operator char *(void); 

    int get_x(void) { return this->x; };
    int get_y(void) { return this->y; };
};

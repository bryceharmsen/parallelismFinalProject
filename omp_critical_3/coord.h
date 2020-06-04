#ifndef COORD_H
#define COORD_H

#include <string>

class Coord {
    double x; /* The x-coordinate of the Coord pair */
    double y; /* The y-coordinate of the Coord pair */

public:
    Coord();
    Coord(double x, double y);
    Coord(const Coord &copy);
    Coord operator=(const Coord &right);
    double get_x();
    double get_y();
    std::string to_string();
};

#endif
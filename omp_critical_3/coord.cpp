#include "coord.h"

Coord::Coord() {
    x = 0.0;
    y = 0.0;
}

Coord::Coord(double x, double y) {
    this->x = x;
    this->y = y;
}

Coord::Coord(const Coord &copy) {
    x = copy.x;
    y = copy.y;
}

Coord Coord::operator=(const Coord &right) {
    if (this != &right) {
        x = right.x;
        y = right.y;
    }

    return (*this);
}

double Coord::get_x() {
    return x;
}

double Coord::get_y() {
    return y;
}

std::string Coord::to_string() {
    return "(" + std::to_string(x) +  ", " + std::to_string(y) + ")";
}
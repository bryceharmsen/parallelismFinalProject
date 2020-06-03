#ifndef RR_H
#define RR_H

#include <iostream>
#include "rand.h"
#include "coord.h"

#define MIN(a,b) ((a)<(b)?(a):(b))
#define LO -10.0
#define HI 10.0

class RR {
    int n;                  /* Number of houses */
    Coord railroad;  /* Railroad coordinate */
    Coord *houses;   /* Array of house coordinates */
    Rand r = Rand(0, 0);    /* Random generator */
    Coord get_rand();
    double get_dist(Coord rr, Coord c);
    double get_dist_sq(Coord rr, Coord c);

public:
    RR(int n);
    RR(const RR &copy);
    RR operator=(const RR &right);
    ~RR();
    Coord get_closest_house();
    void print_dist_results(Coord house);
    void print_coords();
};

#endif
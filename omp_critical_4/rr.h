#ifndef RR_H
#define RR_H

#include <omp.h>
#include <iostream>
#include <unordered_map>
#include "rand.h"

#define MIN(a,b) ((a)<(b)?(a):(b))
#define LO -10.0
#define HI 10.0

class RR {
    int n;                  /* Number of houses */
    double *railroad;     /* Railroad coordinate */
    double **houses;        /* Array of house coordinates */
    Rand r = Rand(0, 0);    /* Random generator */
    void get_rand(double * coord);
    static double get_dist_sq(double *h, double *r);
    double get_dist(double *h, double *r);

public:
    RR(int n);
    RR(const RR &copy);
    RR operator=(const RR &right);
    ~RR();
    double * get_closest_house(int p);
    double * check_closest_house_sequential();
    void print_dist_results(double *house);
    void print_coords();
    std::string coord_to_string(double *coord);
};

#endif
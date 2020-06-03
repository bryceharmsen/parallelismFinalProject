#ifndef RAND_H
#define RAND_H

#include <random>

class Rand {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;
    double low;
    double high;

public:
    Rand(double low, double high);
    Rand(const Rand &copy);
    Rand operator=(const Rand &right);
    double get_rand();
};

#endif
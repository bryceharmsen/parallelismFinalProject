#include "rand.h"

Rand::Rand(const double low, const double high) {
    this->distribution = std::uniform_real_distribution<>(low, high);
    this->low = low;
    this->high = high;
}

Rand::Rand(const Rand &copy) {
    this->distribution = copy.distribution;
    this->generator = copy.generator;
    this->low = copy.low;
    this->high = copy.high;
}

Rand Rand::operator=(const Rand &right) {
    if (this != &right) {
        distribution = right.distribution;
        generator = right.generator;
        low = right.low;
        high = right.high;
    }

    return (*this);
}

double Rand::get_rand() {
    return this->distribution(generator);
}
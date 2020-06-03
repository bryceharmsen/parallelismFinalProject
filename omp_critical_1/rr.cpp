#include "rr.h"

RR::RR(int n) {
    this->n = n;
    this->r = Rand(LO, HI);
    railroad = get_rand();
    houses = new Coord[n];
    for (int i = 0; i < n; i++) {
        houses[i] = get_rand();
    }
}

RR::RR(const RR &copy) {
    n = copy.n;
    r = copy.r;
}

RR::~RR() {
    delete[] houses;
}

RR RR::operator=(const RR &right) {
    if (this != &right) {
        n = right.n;
        r = right.r;
    }

    return (*this);
}

Coord RR::get_rand() {
    Coord c = Coord(r.get_rand(), r.get_rand());
    return c;
}

void RR::print_coords() {
    std::cout << "==== PRINT COORDINATES ====" << std::endl;
    std::cout << "Railroad: " << railroad.to_string() << std::endl;
    std::cout <<"Houses:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "#" << i + 1 << ")\t"
            << houses[i].to_string() << "\tdist "
            << get_dist(railroad, houses[i]) << std::endl;
    }
    std::cout << "=======  END PRINT  =======" << std::endl;
}

void RR::print_dist_results(Coord house) {
    std::cout << "Railroad:\n\t" << railroad.to_string() << std::endl
    << "House:\n\t" << house.to_string() << std::endl
    << "Distance:\n\t" << get_dist(railroad, house) << std::endl;
}

double RR::get_dist(Coord r, Coord c) {
    return pow(get_dist_sq(r, c), 0.5);
}

double RR::get_dist_sq(Coord r, Coord c) {
    double x_diff = r.get_x() - c.get_x(),
           y_diff = r.get_y() - c.get_y();
    return x_diff * x_diff + y_diff * y_diff;
}

Coord RR::get_closest_house(int p) {
    Coord closest = houses[0];
    Coord house;
    double least_dist = __DBL_MAX__;
    double dist;
    int i;
    omp_set_num_threads(p);
    #pragma omp parallel for private(i, house, dist)
    for (i = 0; i < n; i++) {
        house = houses[i];
        dist = get_dist_sq(railroad, house);
        if (dist < least_dist) {
            #pragma omp critical
            {
                least_dist = dist;
                closest = house;
            }
        }
    }

    return closest;
}

Coord RR::check_closest_house_sequential() {
    Coord closest = houses[0];
    Coord house;
    double least_dist = __DBL_MAX__;
    double dist;
    int i;
    for (i = 0; i < n; i++) {
        house = houses[i];
        dist = get_dist_sq(railroad, house);
        if (dist < least_dist) {
                least_dist = dist;
                closest = house;
        }
    }

    return closest;
}
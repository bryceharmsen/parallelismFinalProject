#include "rr.h"

double init[3];

RR::RR(int n) {
    this->n = n;
    this->r = Rand(LO, HI);
    railroad = new double[3];
    get_rand(railroad);
    houses = new double*[n];
    for (int i = 0; i < n; i++) {
        houses[i] = new double[3];
        get_rand(houses[i]);
        houses[i][2] = __DBL_MAX__;
    }
}

RR::RR(const RR &copy) {
    n = copy.n;
    r = copy.r;
}

RR::~RR() {
    for (int i = 0; i < n; i++) {
        delete[] houses[i];
    }
    delete[] houses;
}

RR RR::operator=(const RR &right) {
    if (this != &right) {
        n = right.n;
        r = right.r;
    }

    return (*this);
}

void RR::get_rand(double * coord) {
    coord[0] = r.get_rand();
    coord[1] =  r.get_rand();
}

double RR::get_dist_sq(double *h, double *r) {
    return (h[0] - r[0]) * (h[0] - r[0]) + (h[1] - r[1]) * (h[1] - r[1]);
}

std::string RR::coord_to_string(double *coord) {
    return "(" + std::to_string(coord[0]) +  ", " + std::to_string(coord[1]) + ")";
}

void RR::print_coords() {
    std::cout << "==== PRINT COORDINATES ====" << std::endl;
    std::cout << "Railroad: " << coord_to_string(railroad) << std::endl;
    std::cout <<"Houses:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "#" << i + 1 << ")\t"
            << coord_to_string(houses[i]) << "\tdist "
            << get_dist(houses[i], railroad) << std::endl;
    }
    std::cout << "=======  END PRINT  =======" << std::endl;
}

void RR::print_dist_results(double *house) {
    std::cout << "Railroad:\n\t" << coord_to_string(railroad) << std::endl
    << "House:\n\t" << coord_to_string(house) << std::endl
    << "Distance:\n\t" << get_dist(railroad, house) << std::endl;
}

double RR::get_dist(double * h, double * r) {
    return pow(get_dist_sq(h, r), 0.5);
}

double min(double out, double in) {
    return out > in ? in : out;
}

double * RR::get_closest_house(int p) {
    double *closest = houses[0],
           *internal_closest = houses[0];
    double closest_dist = __DBL_MAX__,
           internal_closest_dist = __DBL_MAX__,
           dist;
    int i, j, closest_i = 0;
    closest[2] = get_dist_sq(closest, railroad);

    omp_set_num_threads(p);

    //group houses into p balanced groups (using indexing groups, step size, blocks, etc.)
    //trim main for loop into the number of processes/threads available
    //inside each iteration of main for loop, find the overall min house of the available houses
    //at main for loop, perform reduction on each processes min

    //in second loop, only look through the n/p sized section for the correct record

    #pragma omp parallel for private(i, j, dist) \
    reduction(min:internal_closest_dist) \
    reduction(min:closest_dist)
    for (i = 0; i < p; i++) {
        //internal_closest_dist = __DBL_MAX__;
        for (j = i * n / p; j < (i + 1) * n / p; j++) {
            dist = get_dist_sq(houses[j], railroad);
            houses[j][2] = dist;

            if (internal_closest_dist > dist)
                internal_closest_dist = dist;
        }

        if (closest_dist > internal_closest_dist)
            closest_dist = internal_closest_dist;
    }

    #pragma omp parallel for private(i)
    for (i = 0; i < n; i++) {
        if (houses[i][2] == closest_dist)
            closest_i = i;
    }

    return houses[closest_i];
}


double * RR::check_closest_house_sequential() {
    double *closest = houses[0];
    double closest_dist_sq = get_dist_sq(closest, railroad);
    int i;

    for (i = 0; i < n; i++) {
        houses[i][2] = get_dist_sq(houses[i], railroad);
        if (closest[2] > houses[i][2])
            closest = houses[i];
    }

    return closest;
}
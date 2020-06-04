#include "benchmarker.h"

Benchmarker::Benchmarker(int n, int p) {
    this->n = n;
    max_procs = p;
    marks = new struct mark[p];
}

Benchmarker::Benchmarker(const Benchmarker &copy) {
    n = copy.n;
    max_procs = copy.max_procs;
    marks = copy.marks;
}

Benchmarker Benchmarker::operator=(const Benchmarker &right) {
    if (this != &right) {
        n = right.n;
        max_procs = right.max_procs;
        marks = right.marks;
    }

    return (*this);
}

Benchmarker::~Benchmarker() {
    delete[] marks;
}

double Benchmarker::get_avg_runtime(int p) {
    double time = 0;
    double *c;
    
    for (int i = 0; i < NUM_RUNS; i++) {
        try {
        RR rr = RR(n);

        clock_gettime(CLOCK_MONOTONIC, &start);
        c = rr.get_closest_house(p);
        time += get_elapsed_time(start, finish);
        
        double *check = rr.check_closest_house_sequential();
        if (check[0] != c[0] || check[1] != c[1])
            throw std::runtime_error("Closest house calculation is incorrect.\n\t"
                                    + rr.coord_to_string(check) + " != " + rr.coord_to_string(c));
        } catch(std::runtime_error re) {
            std::cout << re.what() << std::endl;
        }
    }

    time /= NUM_RUNS;   
    return time;
}

struct mark * Benchmarker::get_runtimes() {
    for (int i = 0; i < max_procs; i++) {
        marks[i].procs = i + 1;
        marks[i].time = get_avg_runtime(i + 1);
    }

    return marks;
}

void Benchmarker::print_runtimes() {
    std::cout << "==== START RUNTIMES ====" << std::endl;
    std::cout << "Threads\tTrial Time" << std::endl;
    for (int i = 0; i < max_procs; i++) {
        std::cout << marks[i].procs << ")\t"
            << marks[i].time << " seconds" << std::endl;
    }
    std::cout << "===== END RUNTIMES =====" << std::endl;
}

double Benchmarker::get_elapsed_time(struct timespec start, struct timespec finish) {
    clock_gettime(CLOCK_MONOTONIC, &finish);
    
    double time = 0;
    
    time = finish.tv_sec - start.tv_sec;
    time += (finish.tv_nsec - start.tv_nsec) / pow(10, 9);

    return time;
}
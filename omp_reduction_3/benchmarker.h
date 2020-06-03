#ifndef BENCHMARKER_H
#define BENCHMARKER_H

#include <iostream>
#include <time.h>
#include "rr.h"

struct mark {
    double time;
    int procs;
};

class Benchmarker {
    const int NUM_RUNS = 50;
    int max_procs, n;
    struct mark *marks;
    struct timespec start, finish;
    double get_avg_runtime(int p);

public:
    Benchmarker(int n, int p);
    Benchmarker(const Benchmarker &copy);
    Benchmarker operator=(const Benchmarker &right);
    ~Benchmarker();
    struct mark *get_runtimes();
    void print_runtimes();
    static double get_elapsed_time(struct timespec start, struct timespec finish);
};

#endif
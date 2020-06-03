#include <stdlib.h>
#include <time.h>
#include "rr.h"

double getElapsedTime(struct timespec start, struct timespec finish) {
    clock_gettime(CLOCK_MONOTONIC, &finish);
    
    double time = 0;
    
    time = finish.tv_sec - start.tv_sec;
    time += (finish.tv_nsec - start.tv_nsec) / pow(10, 9);

    return time;
}

int run(char *arg1) {
    int exit_status = EXIT_SUCCESS;
    struct timespec start, finish;
    double time = 0;
    try {
        int num_houses = std::stoi(arg1);
        RR rr = RR(num_houses);
        std::cout << "Running Railroad..." <<std::endl;
        clock_gettime(CLOCK_MONOTONIC, &start);
        Coord house = rr.get_closest_house();
        time = getElapsedTime(start, finish);
        std::cout << "Elapsed Time: " << time
            << " seconds" << std::endl;
        rr.print_dist_results(house);
    } catch (std::runtime_error re) {
        std::cout << re.what() << std::endl;
        exit_status = 2;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
        exit_status = EXIT_FAILURE;
    }

    return exit_status;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Proper use:\n\t" << argv[0]
            << " <number_of_houses>" << std::endl;
        return EXIT_FAILURE;
    }

    int exit_status = run(argv[1]);

    std::cout << "Exiting " << argv[0] << " successfully." << std::endl;
    return exit_status;
}
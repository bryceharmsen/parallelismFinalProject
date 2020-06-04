#include <stdlib.h>
#include <time.h>
#include "rr.h"
#include "benchmarker.h"

int run(char *arg1, char *arg2) {
    int exit_status = EXIT_SUCCESS;
    struct timespec start, finish;
    double time = 0;
    try {
        int num_houses = std::stoi(arg1);
        int num_threads = std::stoi(arg2);

        Benchmarker bmkr = Benchmarker(num_houses, num_threads);
        struct mark * mrk = bmkr.get_runtimes();
        bmkr.print_runtimes();
        
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
    if (argc != 3) {
        std::cout << "Proper use:\n\t" << argv[0]
            << " <number_of_houses> <num_threads>" << std::endl;
        return EXIT_FAILURE;
    }

    int exit_status = run(argv[1], argv[2]);

    std::cout << "Exiting " << argv[0] << " successfully." << std::endl;
    return exit_status;
}
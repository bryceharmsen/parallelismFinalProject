#include <stdio.h>
#include <stdlib.h>

int run(int argc, char** argv) {
    printf("Running %s...\n", argv[0]);
}

int main(int argc, char** argv) {
    run(argc, argv);
    printf("Exiting %s succesfully.\n", argv[0]);
    return EXIT_SUCCESS;
}
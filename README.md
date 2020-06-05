# Parallel Computing Final Project

The goal of this project is to implement a parallel program in OpenMP, MPI, or CUDA to solve either problem 3.13, 3.14, 3.15, or 3.16 from *Parallel Programming in C with MPI and OpenMP*.

## Problem Description

3.15
You are given an array of *n* records, each containing the *x* and *y* coordinates of a house. You are also given the *x* and *y* coodinates of a railroad station. Design a parallel algorithm to find the house closest to the railroad station (as the crow flies).

## The code

Each omp_\* directory contains a different implementation of the parallelized solution to problem 3.15. The different implementations are explained in the report, labelled *473_Final_Project*. The executables and source code are contained within each directory, which leads to a large amount of duplicated code among the directories. The main differences are in rr.cpp, namely in function **RR::get_closest_house(int p)**. All executable were created on Ubuntu 18.04 using g++ 7.5.0. Implementation of OpenMP requires version 3.*x* because of the use of omp-defined min reduction.

In the case that you wish to compile any of this code, please run:
```g++ -o EXEC_NAME <all .cpp files in chosen directory separated by spaces> -fopenmp```

For further questions, please contact Bryce Harmsen.
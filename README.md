# Parallel Computing Final Project

The goal of this project is to implement a parallel program in OpenMP, MPI, or CUDA to solve either problem 3.13, 3.14, 3.15, or 3.16 from *Parallel Programming in C with MPI and OpenMP*.

## Problem Description

3.15
You are given an array of *n* records, each containing the *x* and *y* coordinates of a house. You are also given the *x* and *y* coodinates of a railroad station. Design a parallel algorithm to find the house closest to the railroad station (as the crow flies).

## Design

Based on Foster's methodology, this is the progression of parallelizing this problem:

### Partitioning

Write the partitioning step here and draw a primitive tasks diagram.

### Communication

Write the comm. step here

### Agglomeration and Mapping

Write the agglomeration and mapping step here and draw an agglomerated tasks diagram.

### Mapping

Write the mapping step here

## Benchmarking

Display information about the execution time based on *n* and *p*, comparing also to the sequential algorithm.

## Theoretical Efficiency

Compare parallel vs. sequential asymptotic execution time assessing computation and communication times with some big-oh claims.

## Discussion

Write discussion, conclusions, assessments of performance and parallel architecture of the problem here.
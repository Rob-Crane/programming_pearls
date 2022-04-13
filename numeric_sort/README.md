# Sorting Unique, Bounded Integers

Programs to generate a random permutation of integers less than n and a program to sort them.

Demonstrates performance improvement of using a bitmap based approach since range of values is very limited.

Run as follows:
```
g++ -std=c++11 -o generate_random_numbers generate_random_numbers.cpp
g++ -std=c++11 -o fast_sort fast_sort.cpp

# Generate random order of first 10m integers.
generate_random_numbers 10000000

# Display time for system sort.
time sort -n -o sorted.txt numbers.txt

# Display time for fast_sort.
time fast_sort
```

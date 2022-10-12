cmake_minimum_required(VERSION 3.22)
project(Algo_Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algo_Lab Insertion_sort.cpp Counting_Sort.cpp Radix_sort.cpp Merge_sort.cpp Bubble_sort.cpp Kruskal_mst.cpp Quicksort.cpp Selection_sort.cpp Binary_search_2d_array.cpp Fraction_knapsack.cpp Prims_mst.cpp Quick_sort_lemda.cpp 0-1_Knapsack.cpp merge_sort_lemda.cpp)

add_executable(Insertion_sort Insertion_sort.cpp)

add_executable(Counting_Sort Counting_Sort.cpp)
add_executable(Radix_sort Radix_sort.cpp)
add_executable(Merge_sort Merge_sort.cpp)
add_executable(Bubble_sort Bubble_sort.cpp)
add_executable(Kruskal_mst Kruskal_mst.cpp)
add_executable(Quicksort Quicksort.cpp)
add_executable(Selection_sort Selection_sort.cpp)
add_executable(Binary_search_2d_array Binary_search_2d_array.cpp)
add_executable(Fraction_knapsack Fraction_knapsack.cpp)
add_executable(Prims_mst Prims_mst.cpp)
add_executable(Quick_sort_lemda Quick_sort_lemda.cpp)
add_executable(0-1_Knapsack 0-1_Knapsack.cpp)
add_executable(Merge_sort_again merge_sort_lemda.cpp)
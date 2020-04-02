cmake_minimum_required(VERSION 3.15)
project(Sortownia)

set(CMAKE_CXX_STANDARD 11)

add_executable(Sortownia main.cpp Quicksort.cpp Quicksort.h Mergesort.cpp Mergesort.h Introsort.cpp Introsort.h)
cmake_minimum_required(VERSION 3.25)
project(CSE331_DSA_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSE331_DSA_Project main.cpp headers.h Tree.cpp pretty.cpp treeparse.cpp Convert.cpp minifier.cpp Validity.cpp CompDec.cpp)

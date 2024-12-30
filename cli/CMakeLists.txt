cmake_minimum_required(VERSION 3.25)
project(CSE331_DSA_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSE331_DSA_Project main.cpp ../external/headers.h ../external/Tree.cpp ../external/pretty.cpp ../external/treeparse.cpp
        ../external/Convert.cpp ../external/minifier.cpp ../external/Validity.cpp ../external/CompDec.cpp ../external/postGraph.h
        ../external/postGraph.cpp  ../external/graphAnalysis.cpp ../external/graphParsing.cpp ../external/graph.hpp ../external/Search.cpp ../external/socialGraph.cpp
        ../external/drawGraph/drawGraph.cpp)

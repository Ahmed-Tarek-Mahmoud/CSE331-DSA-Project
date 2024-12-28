#pragma once

#include "graphParsing.hpp"
#include <fstream>
#include <cstdlib>

/**
 * @file drawGraph.hpp
 * @brief Provides functions for exporting graph data to a file, drawing graphs using a Python script,
 *        and running the necessary script for visualization.
 */

/**
 * @brief Parses the input file, writes graph data to a temporary file, and runs a Python script
 *        to generate a graph visualization.
 *
 * @param inputFileName The name of the input file containing graph data.
 * @param outputFileName The name of the file where the graph visualization will be saved.
 */
void drawGraph(const char *inputFileName, const char *outputFileName);

/**
 * @brief Writes the graph data from a Graph object to a temporary file in a specified format.
 *
 * The file includes the output file name in the first line
 * followed by lines representing graph edges in the format `<node1> <node2>`.
 *
 * @param usersGraph A reference to the Graph object containing graph data.
 * @param outputFileName The name of the file where the graph visualization will be saved.
 */
void writeGraphToFile(const Graph &usersGraph, const char *outputFileName);

/**
 * @brief Executes a Python script to create a graph visualization.
 *
 * The script reads graph data from a file and generates the visualization. The Python script
 * must be available in the same directory
 */
void runPythonScript();

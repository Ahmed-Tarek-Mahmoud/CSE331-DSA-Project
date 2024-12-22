#pragma once

#include "graph.hpp"

/**
 * @file graphParsing.hpp
 * @brief Header file for graph parsing and utility functions.
 *
 * This file declares functions for parsing a social network graph
 * from an XML file and for manipulating the `Graph` structure.
 */

/**
 * @brief Parses a social network graph from an input XML file.
 *
 * This function reads an input XML file and constructs a `Graph` structure
 * representing users, their names, followers, and the following relationships.
 *
 * @param inputFileName The name of the input XML file.
 * @return A `Graph` object containing the parsed data.
 */
Graph graphParsing(const char *inputFileName);

/**
 * @brief Constructs the `id_to_following` map in the `Graph` structure.
 *
 * This function populates the `id_to_following` field in the given `Graph` object
 * based on the `id_to_followers` field.
 *
 * This function is used by graphParsing function
 *
 * @param g Reference to the `Graph` object.
 */
void idToFollowing(Graph &g);

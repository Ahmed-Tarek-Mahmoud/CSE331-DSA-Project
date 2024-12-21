#pragma once

#include "graphParsing.hpp"

/**
 * @file graphAnalysis.hpp
 * @brief Header file for graph analysis functions.
 *
 * This file declares functions for analyzing a social network graph
 * to determine influential and active users.
 */

/**
 * @brief Finds the most influential user in the graph by parsing an input file.
 *
 * The most influential user is determined as the one with the maximum number
 * of followers.
 *
 * @param inputFileName Path to the input file containing the graph data.
 * @return A pair containing the user ID and name of the most influential user.
 */
pair<int, string> mostInfluential(const char *inputFileName);

/**
 * @brief Finds the most active user in the graph by parsing an input file.
 *
 * The most active user is determined as the one with the highest sum of
 * connections, including both followers and followings.
 *
 * @param inputFileName Path to the input file containing the graph data.
 * @return A pair containing the user ID and name of the most active user.
 */
pair<int, string> mostActiveUser(const char *inputFileName);

/**
 * @brief Finds the most influential user in a given graph.
 *
 * This is an internal function that processes an existing graph object.
 *
 * @param g The `Graph` object representing the social network.
 * @return A pair containing the user ID and name of the most influential user.
 */
pair<int, string> mostInfluential_internal(Graph &g);

/**
 * @brief Finds the most active user in a given graph.
 *
 * This is an internal function that processes an existing graph object.
 *
 * @param g The `Graph` object representing the social network.
 * @return A pair containing the user ID and name of the most active user.
 */
pair<int, string> mostActiveUser_internal(Graph &g);

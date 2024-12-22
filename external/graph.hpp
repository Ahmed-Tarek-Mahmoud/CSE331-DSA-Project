#pragma once

#include "headers.h"
#include <unordered_map>
#include <unordered_set>

/**
 * @file Graph.hpp
 * @brief Header file defining the Graph structure for representing a social network.
 *
 * This file contains the definition of the `Graph` structure, which can be used to represent
 * relationships in a social network, such as followers and following relationships.
 * It uses efficient data structures from the C++ Standard Library for storing and querying the data.
 */

/**
 * @brief A structure to represent a social network graph.
 *
 * The `Graph` structure contains the following components:
 * - A mapping of user IDs to their names.
 * - Followers and following relationships.
 * - A count of connections for each user.
 */
struct Graph
{
    /**
     * @brief Maps user IDs to their corresponding names.
     *
     * The key is an integer user ID, and the value is a string representing the user's name.
     */
    unordered_map<int, std::string> id_to_name;

    /**
     * @brief Maps user IDs to their list of followers.
     *
     * The key is an integer user ID, and the value is a vector of integers representing the IDs
     * of users who follow this user.
     */
    unordered_map<int, std::vector<int>> id_to_followers;

    /**
     * @brief Maps user IDs to their set of users they are following.
     *
     * The key is an integer user ID, and the value is an unordered set of integers representing the IDs
     * of users this user is following.
     */
    unordered_map<int, std::unordered_set<int>> id_to_following;

    /**
     * @brief Stores the count of total connections for each user.
     *
     * The key is an integer user ID, and the value is the total number of connections
     * (e.g., followers + following) associated with this user.
     */
    unordered_map<int, int> connectionsCount;
};

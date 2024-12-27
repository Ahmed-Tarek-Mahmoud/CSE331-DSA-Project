#pragma once
#include "graphParsing.hpp"
// Finds mutual connections between two users
// @param userIds - vector of user IDs
// @param inputFile - Path to the input file representing the social graph
// @return unordered set of user IDs representing mutual connections
unordered_set<int> mutual(const vector<int>& userIds, const char* inputFile);

// Finds mutual connections between two users based on a given graph
// @param userIds - vector of user IDs
// @param following - Unordered map representing user following connections
// @return unordered set of user IDs representing mutual connections
unordered_set<int> mutual(const vector<int>& userIds, const unordered_map<int, unordered_set<int>>& following);

// Suggests new connections for a user
// @param userId - ID of the user
// @param inputFile - Path to the input file representing the social graph
// @return Vector of user IDs representing suggested connections
vector<int> suggest(int userId, const char* inputFile);

// Suggests new connections for a user based on a given graph
// @param userId - ID of the user
// @param following - Unordered map representing user connections
// @return Vector of user IDs representing suggested connections
vector<int> suggest(int userId, unordered_map<int,unordered_set<int>> following);



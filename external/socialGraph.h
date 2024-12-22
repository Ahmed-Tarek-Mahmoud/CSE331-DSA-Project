#pragma once
#include "graphParsing.hpp"
// Finds mutual connections between two users
// @param user1Id - ID of the first user
// @param user2Id - ID of the second user
// @param inputFile - Path to the input file representing the social graph
// @return Vector of user IDs representing mutual connections
vector<int> mutual(int user1Id, int user2Id, const char* inputFile);

// Finds mutual connections between two users based on a given graph
// @param user1Id - ID of the first user
// @param user2Id - ID of the second user
// @param following - Unordered map representing user connections
// @return Vector of user IDs representing mutual connections
vector<int> mutual(int user1Id, int user2Id, unordered_map<int,unordered_set<int>> following);

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
vector<int> suggest(int userId, unordered_map<int,unordered_set<int>> following);


#include "socialGraph.h"

// Finds mutual connections between two users by parsing the input file
vector<int> mutual(int user1Id, int user2Id, const char* inputFile) {
    // Parse the input file to create a graph representation
    Graph userGraph = graphParsing(inputFile);
    // Call the overloaded mutual function with the parsed graph data
    return mutual(user1Id, user2Id, userGraph.id_to_following);
}

// Overloaded function to find mutual connections using an existing graph
vector<int> mutual(int user1Id, int user2Id, unordered_map<int,unordered_set<int>> following) {
    vector<int> mutualConnections;

    // Iterate through the following list of user1 and check for mutual connections
    for (int elem : following[user1Id]) {
        if (following[user2Id].find(elem) != following[user2Id].end()) {
            mutualConnections.push_back(elem);
        }
    }
    return mutualConnections;
}

// Suggests new connections for a user by parsing the input file
vector<int> suggest(int userId, const char* inputFile) {
    Graph userGraph = graphParsing(inputFile);
    return suggest(userId, userGraph.id_to_following);
}

// Overloaded function to suggest connections using an existing graph
vector<int> suggest(int userId, unordered_map<int, unordered_set<int>> following) {
    vector<int> suggestions;

    // Iterate through direct connections of the user
    for (int followingDirect : following[userId]) {
        // Iterate through the connections of the direct connections
        for (int suggestion : following[followingDirect]) {
            // Suggest the user if not already followed and not the user himself
            if ((suggestion != userId) && (following[userId].find(suggestion) == following[userId].end())) {
                suggestions.push_back(suggestion);
            }
        }
    }
    return suggestions;
}

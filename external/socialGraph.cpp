#include "socialGraph.h"

// Finds mutual connections between Multiple users 
unordered_set<int> mutual(const vector<int>& userIds, const char* inputFile) {

    Graph userGraph = graphParsing(inputFile);
    return mutual(userIds, userGraph.id_to_following);

}

unordered_set<int> mutual(const vector<int>& userIds, const unordered_map<int, unordered_set<int>>& following) {
    if (userIds.empty()) return {};

    // Initialize set with following set of the first user
    unordered_set<int> mutualSet = following.at(userIds[0]);

    for (size_t i = 1; i < userIds.size(); ++i) {
        unordered_set<int> tempSet;

        // Check each element in mutualSet if it is also in the following set of the current user
        for (int elem : mutualSet) {
            if (following.at(userIds[i]).find(elem) != following.at(userIds[i]).end()) {
                tempSet.insert(elem);
            }
        }
        // Update mutualSet to be the intersection of itself and the current user's following set
        mutualSet = std::move(tempSet);
    }

    return mutualSet;
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

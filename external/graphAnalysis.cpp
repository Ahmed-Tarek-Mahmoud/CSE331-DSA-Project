#include "graphAnalysis.hpp"

pair<int, string> mostInfluential(const char *inputFileName)
{
    Graph usersGraph = graphParsing(inputFileName);
    return mostInfluential_internal(usersGraph);
}

pair<int, string> mostInfluential_internal(Graph &g)
{
    int maxFollowers = 0;
    int mostInfluentialId = 0;

    for (auto it = g.id_to_followers.begin(); it != g.id_to_followers.end(); ++it)
    {
        int currentUserId = it->first;
        int followersCount = it->second.size();

        if (followersCount > maxFollowers)
        {
            maxFollowers = followersCount;
            mostInfluentialId = currentUserId;
        }
    }

    return {mostInfluentialId, g.id_to_name[mostInfluentialId]};
}

pair<int, string> mostActiveUser(const char *inputFileName)
{
    Graph usersGraph = graphParsing(inputFileName);
    return mostActiveUser_internal(usersGraph);
}

pair<int, string> mostActiveUser_internal(Graph &g)
{
    int maxConnections = 0;
    int mostActiveUserId = 0;

    // Count followers
    for (auto it = g.id_to_followers.begin(); it != g.id_to_followers.end(); ++it)
    {
        int userId = it->first;
        int followersCount = it->second.size();

        g.connectionsCount[userId] += followersCount;
    }

    // Count followings
    for (auto it = g.id_to_following.begin(); it != g.id_to_following.end(); ++it)
    {
        int userId = it->first;
        int followingsCount = it->second.size();

        g.connectionsCount[userId] += followingsCount;
    }

    // Find the user with the maximum connections
    for (auto it = g.connectionsCount.begin(); it != g.connectionsCount.end(); ++it)
    {
        int userId = it->first;
        int totalConnections = it->second;

        if (totalConnections > maxConnections)
        {
            maxConnections = totalConnections;
            mostActiveUserId = userId;
        }
    }

    return {mostActiveUserId, g.id_to_name[mostActiveUserId]};
}

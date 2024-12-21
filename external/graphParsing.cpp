#include "graphParsing.hpp"

void idToFollowing(Graph &g)
{
    // Copying keys (users) in the following map
    for (auto it = g.id_to_followers.begin(); it != g.id_to_followers.end(); ++it)
    {
        g.id_to_following[it->first] = unordered_set<int>();
    }

    // Iterating through the followers map to construct the following map
    for (auto it = g.id_to_followers.begin(); it != g.id_to_followers.end(); ++it)
    {
        for (int element : it->second)
        {
            g.id_to_following[element].insert(it->first);
        }
    }
}

Graph graphParsing(const char *inputFileName)
{
    FILE *inFile = fopen(inputFileName, "r");
    if (!inFile)
    {
        fprintf(stderr, "Error: Could not open input file: %s\n", inputFileName);
        return Graph(); // Return an empty graph
    }

    char ch;
    string inputFile;
    while ((ch = fgetc(inFile)) != EOF)
    {
        inputFile += ch;
    }
    fclose(inFile);

    string line, currentTag;
    int userId;
    string userName;
    vector<int> followers;
    Graph usersGraph;

    for (size_t i = 0; i < inputFile.length(); i++)
    {
        if (inputFile[i] == '<' && inputFile[i + 1] != '/')
        {
            currentTag.clear();
            line.clear();
            while (inputFile[++i] != '>')
            {
                currentTag += inputFile[i];
            }

            if (currentTag == "id")
            {
                while (inputFile[++i] != '<')
                {
                    if (inputFile[i] != ' ')
                        line += inputFile[i];
                }
                userId = stoi(line);
            }
            else if (currentTag == "name")
            {
                bool insideWord = false;      // Flag to track if we are reading a word
                while (inputFile[++i] != '<') // Read until the closing tag
                {
                    if (!isspace(inputFile[i])) // Include non-space characters
                    {
                        line += inputFile[i];
                        insideWord = true; // Currently inside a word
                    }
                    else if (insideWord) // Include a single space only between words
                    {
                        line += ' ';
                        insideWord = false; // Reset for the next word
                    }
                }
                userName = line;
            }
            else if (currentTag == "follower")
            {
                while (inputFile[++i] != '<' || inputFile[i + 1] != '/')
                {
                    if (isdigit(inputFile[i]) && inputFile[i] != ' ')
                        line += inputFile[i];
                }
                if (!line.empty())
                {
                    followers.push_back(stoi(line));
                }
            }
        }
        else if (inputFile[i] == '<' && inputFile[i + 1] == '/')
        {
            currentTag = "";
            i++; // ignore '/'
            while (inputFile[++i] != '>')
            {
                currentTag += inputFile[i];
            }

            if (currentTag == "user") // closing tag for user
            {
                usersGraph.id_to_name[userId] = userName;
                usersGraph.id_to_followers[userId] = followers;
                followers.clear();
            }
        }
    }

    idToFollowing(usersGraph); // constructing id to following map

    return usersGraph;
}

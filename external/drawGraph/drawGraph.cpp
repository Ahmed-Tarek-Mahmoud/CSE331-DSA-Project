#include "drawGraph.hpp"

void drawGraph(const char *inputFileName, const char *outputFileName)
{
    // create a graph object to draw
    Graph usersGraph = graphParsing(inputFileName);
    // write the graph into a format readable by python code
    writeGraphToFile(usersGraph, outputFileName);
    // run python application to draw the graph
    runPythonScript();
}

void writeGraphToFile(const Graph &usersGraph, const char *outputFileName)
{
    std::ofstream file("graph_data.txt");
    if (file.is_open())
    {
        file << outputFileName << "\n";
        for (const auto &[user, followers] : usersGraph.id_to_following)
        {
            for (int follower : followers)
            {
                file << user << " " << follower << "\n";
            }
        }
        file.close();
        std::cout << "Graph data written to file.\n";
    }
    else
    {
        std::cerr << "Failed to open file for writing.\n";
    }
}

void runPythonScript()
{
    int result = system("./draw_graph");
    if (result == 0)
    {
        std::cout << "Python script executed successfully.\n";
    }
    else
    {
        std::cerr << "Error running Python script.\n";
    }
}

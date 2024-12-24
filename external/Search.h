#ifndef SEARCH_H
#define SEARCH_H

#include <unordered_map>
#include <vector>
#include <string>
#include "postGraph.h"

using namespace std;

class Search {
private:
    unordered_map<string, vector<post*>> words;
    unordered_map<string, vector<post*>> topics;

    vector<string> splitIntoWords(const string& str); //Helper

public:

    Search();

    void generateWords();
    void generateTopics();

    vector<post*> searchWord(const string& word);
    vector<post*> searchTopic(const string& topic);
};

#endif

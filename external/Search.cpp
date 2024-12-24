#include "search.h"

// Constructor
Search::Search() {
    // Empty maps
}

// Split a string into words using spaces
vector<string> Search::splitIntoWords(const string& str) {
    vector<string> words;
    int start = 0, spacePos;
    while ((spacePos = str.find(' ', start)) != -1) { // Find next space
        if (spacePos != start) { // Avoid empty words
            words.push_back(str.substr(start, spacePos - start)); // Extract the word
        }
        start = spacePos + 1;
    }
    if (start < str.size()) {
        words.push_back(str.substr(start)); // Add the last word
    }
    return words;
}

// Generate the topics map
void Search::generateTopics() {
    // Loop through all user posts
    for (int i = 0; i < postGraph.size(); i++) {
        // Loop through each post
        for(int j = 0; j < postGraph[i].size(); j++) {
            topics[postGraph[i][j]->topic].push_back(postGraph[i][j]);
        }
    }
}

// Generate the words map
void Search::generateWords() {
    // Loop through all user posts
    for (int i = 0; i < postGraph.size(); i++) {
        // Loop through each post
        for(int j = 0; j < postGraph[i].size(); j++) {
            vector<string> wordList = splitIntoWords(postGraph[i][j]->body); // Split into words
            // Loop through wordList
            for ( string word : wordList) {
                words[word].push_back(postGraph[i][j]);
            }
        }
    }
}

// Search for posts by topic
vector<post*> Search::searchTopic(const string& topic) {
    if (topics.find(topic) != topics.end()) {
        return topics[topic];
    }
    return {};
}

// Search for posts by word
vector<post*> Search::searchWord(const string& word) {
    if (words.find(word) != words.end()) {
        return words[word];
    }
    return {};
}

#include "CompDec.h"
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <stdexcept>

// Read a file and return its content as a string
string CompDec::read_file(const string& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) throw runtime_error("Could not open file.");
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Write a string to a file
void CompDec::write_file(const string& file_path, const string& content) {
    ofstream file(file_path);
    if (!file.is_open()) throw runtime_error("Could not open file.");
    file << content;
}

// LZW Compression
vector<int> CompDec::compress(const string& input) {
    unordered_map<string, int> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[string(1, i)] = i;
    }

    string current;
    vector<int> result;
    int code = 256;

    for (char ch : input) {
        string next = current + ch;
        if (dictionary.find(next) != dictionary.end()) {
            current = next;
        } else {
            result.push_back(dictionary[current]);
            dictionary[next] = code++;
            current = string(1, ch);
        }
    }

    if (!current.empty()) {
        result.push_back(dictionary[current]);
    }
    return result;
}

// Convert compressed data to string
string CompDec::compressed_data_to_string(const vector<int>& compressed_data) {
    stringstream ss;
    for (int code : compressed_data) {
        ss << code << " ";
    }
    return ss.str();
}

// Convert string to compressed data
vector<int> CompDec::string_to_compressed_data(const string& data_str) {
    stringstream ss(data_str);
    vector<int> compressed_data;
    int code;
    while (ss >> code) {
        compressed_data.push_back(code);
    }
    return compressed_data;
}

// LZW Decompression
string CompDec::decompress(const vector<int>& compressed_data) {
    unordered_map<int, string> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[i] = string(1, i);
    }

    string current = dictionary[compressed_data[0]];
    string result = current;
    int code = 256;

    for (size_t i = 1; i < compressed_data.size(); ++i) {
        int key = compressed_data[i];
        string entry;

        if (dictionary.find(key) != dictionary.end()) {
            entry = dictionary[key];
        } else if (key == code) {
            entry = current + current[0];
        } else {
            throw runtime_error("Invalid compressed data.");
        }

        result += entry;

        dictionary[code++] = current + entry[0];
        current = entry;
    }

    return result;
}

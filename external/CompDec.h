#ifndef COMP_DEC_H
#define COMP_DEC_H

#include <string>
#include <vector>

using namespace std;

class CompDec {
public:
    // Constructor
    CompDec() = default;

    // Function to read a file and return its content as a string
    static string read_file(const string& file_path);

    // Function to write a string to a file
    static void write_file(const string& file_path, const string& content);

    // LZW Compression
    static vector<int> compress(const string& input);

    // LZW Decompression
    static string decompress(const vector<int>& compressed_data);

    // Convert compressed data to a string format for saving to a file
    static string compressed_data_to_string(const vector<int>& compressed_data);

    // Convert string format back to compressed data
    static vector<int> string_to_compressed_data(const string& data_str);
};

#endif

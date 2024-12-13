// CompDec.h
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
    static string read_file(string& file_path);

    // Function to write a string to a file
    static void write_file(const string& file_path, const string& content);

    // Binary file read/write for compressed data
    static void write_binary_file(const string& file_path, const vector<int>& data);
    static vector<int> read_binary_file(const string& file_path);

    // LZW Compression
    static vector<int> compress(const string& input);

    // LZW Decompression
    static string decompress(const vector<int>& compressed_data);
};

#endif

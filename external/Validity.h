
#ifndef VALIDITY_H
#define VALIDITY_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* Error Class for custom errors*/
class error {

private:
    string message;
    int line;
public:
    error(string m,int l);
    string print_error() ;
    string getMessage() const;
    int getLineNumber() const;
};

 /*Prototype for file validation and error correction function */
vector<error> validityCheck_Correction(string path,vector<string> & correctOutput);


#endif //VALIDITY_H

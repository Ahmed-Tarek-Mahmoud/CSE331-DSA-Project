
#include "Tree.h"
#include <iostream>
#include <fstream>

using namespace std;

class error {
private:
  string message;
public:

  error(string m) {
    message = m;
  }

  string print_error() {
    return "Error: " + message;
  }

  string getMessage() const {
    return message;
  }

};

vector<error> validityCheck_Correction(ifstream &file,ofstream &outfile) {
  outfile.clear();
  vector<error> errors;
  vector<string> correctOutput;
  vector<string> openTagVector;
  string line;
  int lineNumber =0;

  while (getline(file, line)) {
    string openingTag,closingTag,data;
    int i=0;

    while (line[i] == 32 || line[i] == '\t' && i< line.length()) {
      i++;
    }

    if (line[i] == '<' && line[i+1] != '/') {
      for (; i<line.length(); i++) {
        if (line[i] == '<') {continue;}
        if (line[i] != '>') {
          openingTag+=line[i];
        }else {
          i++;
          break;
        }
      }
    }

    while (line[i] != '<' && line[i] != '>' && i< line.length()) {
      data+=line[i];
      i++;
    }

    //Obtain closingTag
    if (line[i] == '<' && line[i+1] == '/' && i != line.length()) {
      for (; i<line.length(); i++) {
        if (line[i] == '<') {continue;}
        if (line[i] != '>') {
          closingTag+=line[i];
        } else break;
      }
    }else if (line[i] == '<' && line[i+1] != '/') { //check if closing tag is the same as opening tag (i.e. without '/')
      for (; i<line.length(); i++) {
        if (line[i] == '<') {continue;}
        if (line[i] != '>') {
          closingTag+=line[i];
        }else break;
      }
    }

    lineNumber++;

    if (lineNumber == 6) {
      cout<<"";
    }
    if (openingTag.empty() && closingTag.empty() && !data.empty()) {

      correctOutput.push_back(data);

    }else if (!openingTag.empty() && !closingTag.empty()) {

      correctOutput.push_back("<"+openingTag+">");
      if (!data.empty()) {correctOutput.push_back(data);}
      if (closingTag == "/"+openingTag) {
        correctOutput.push_back("<"+closingTag+">");
      }else {
        errors.push_back(error("INCORRECT_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openingTag));
        correctOutput.push_back("</"+openingTag+">");
        if (closingTag[0] == '/') {
          correctOutput.push_back("<"+closingTag.substr(1)+">");
          correctOutput.push_back("<"+closingTag+">");

        }else {
          correctOutput.push_back("<"+closingTag+">");
          correctOutput.push_back("</"+closingTag+">");
        }
      }

    }else if (!openingTag.empty() && closingTag.empty() && !data.empty()) {

      errors.push_back(error("MISSING_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openingTag));
      correctOutput.push_back("<"+openingTag+">");
      correctOutput.push_back(data);
      correctOutput.push_back("</"+openingTag+">");

    }else if (!openingTag.empty() && closingTag.empty() && data.empty()) {

      bool found = false;

      for (int i=0; i<openTagVector.size(); i++) {
        if (openTagVector[i] == openingTag) {
          found = true;
          break;
        }
      }

      if (found) {
        errors.push_back(error("MISSING_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openingTag));
        while (openTagVector.back() != openingTag) {
          correctOutput.push_back("</"+openTagVector.back()+">");
          openTagVector.pop_back();
        }
        correctOutput.push_back("</"+openingTag+">");
        correctOutput.push_back("<"+openingTag+">");
      }else {

        openTagVector.push_back(openingTag);
        correctOutput.push_back("<"+openingTag+">");

      }

    }else if (openingTag.empty() && !closingTag.empty()) {

      if (!openTagVector.empty() && closingTag == "/"+openTagVector.back()) {
        correctOutput.push_back("<"+closingTag+">");
        openTagVector.pop_back();

      }else {
        bool found = false;
        for (int i=0; i<openTagVector.size(); i++) {
          if (closingTag == "/"+openTagVector[i]) {
            found = true;
            break;
          }
        }
        if (found) {
          while (closingTag != "/"+openTagVector.back()) {
            errors.push_back(error("MISSING_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openTagVector.back()));
            correctOutput.push_back("</"+openTagVector.back()+">");
            openTagVector.pop_back();
          }
          correctOutput.push_back("<"+closingTag+">");
          openTagVector.pop_back();
        }else {
          errors.push_back(error("MISSING_OPENING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + closingTag.substr(1)));
          correctOutput.push_back("<"+closingTag.substr(1)+">");
          correctOutput.push_back("<"+closingTag+">");
        }
      }
    }

  }
    if (outfile.is_open()) {
      for (int i=0; i<correctOutput.size(); i++) {
        outfile << correctOutput[i] << endl;
      }
    }

    return errors;
}



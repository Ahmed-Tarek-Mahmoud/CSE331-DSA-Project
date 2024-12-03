
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
  stack<string> openingTagStack;
  stack<string> closingTagStack;
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
      }

    }else if (!openingTag.empty() && closingTag.empty() && !data.empty()) {

      errors.push_back(error("MISSING_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openingTag));
      correctOutput.push_back("<"+openingTag+">");
      correctOutput.push_back(data);
      correctOutput.push_back("</"+openingTag+">");

    }else if (!openingTag.empty() && closingTag.empty() && data.empty()) {

      if (!openingTagStack.empty() && openingTag  == openingTagStack.top()) {

        errors.push_back(error("MISSING_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openingTag));
        correctOutput.push_back("</"+openingTag+">");

      }else {

        openingTagStack.push(openingTag);

      }
      correctOutput.push_back("<"+openingTag+">");

    }else if (openingTag.empty() && !closingTag.empty()) {

      if (!openingTagStack.empty() && closingTag == "/"+openingTagStack.top()) {

        correctOutput.push_back("<"+closingTag+">");
        openingTagStack.pop();

      }else {
        while (!openingTagStack.empty() && closingTag != "/"+openingTagStack.top()) {
          errors.push_back(error("MISSING_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openingTagStack.top()));
          correctOutput.push_back("</"+openingTagStack.top()+">");
          openingTagStack.pop();

        }

        correctOutput.push_back("<"+closingTag+">");
        openingTagStack.pop();

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



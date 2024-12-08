
#include "Validity.h"

  error::error(string m,int l) {
    message = m;
    line = l;
  }

  string error:: print_error() {
    return "Error: " + message;
  }

  string error:: getMessage() const {
    return message;
  }


vector<error> validityCheck_Correction(string path) {

  fstream file;
  file.open(path);

  vector<string> correctOutput; //Vector for storing correct output
  vector<string> openTagVector; //Vector for storing open tags
  vector<error> errors; //Vector for storing errors found in the file

  string line; //String for storing line read by stream
  int lineNumber = 0; //Holds the value for line currently being read

  //Reads the file line by line
  while (getline(file, line)) {
    string openingTag,closingTag,data;
    int i=0;

    //Skip blank spaces
    while (line[i] == 32 || line[i] == '\t' && i< line.length()) {
      i++;
    }

    //Obtain opening tag
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

    //Skip blank spaces
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
    //check if closing tag is the same as opening tag (i.e. without '/')
    }else if (line[i] == '<' && line[i+1] != '/') {
      for (; i<line.length(); i++) {
        if (line[i] == '<') {continue;}
        if (line[i] != '>') {
          closingTag+=line[i];
        }else break;
      }
    }

    //Increment line number
    lineNumber++;
    if (lineNumber==34) {
      cout << "";
    }
    // If data only is present
    if (openingTag.empty() && closingTag.empty() && !data.empty()) {

      correctOutput.push_back(data);

    }else if (!openingTag.empty() && !closingTag.empty()) { //If both opening tag and closing tags are present

      correctOutput.push_back("<"+openingTag+">");
      if (!data.empty()) {correctOutput.push_back(data);}
      //If closing tag matches then no errors
      if (closingTag == "/"+openingTag) {
        correctOutput.push_back("<"+closingTag+">");
      //If closing tag doesn't match then close the current tag correctly
      }else {
        errors.push_back(error("INCORRECT_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openingTag,lineNumber));
        correctOutput.push_back("</"+openingTag+">");
        //If closing tag starts with '/' then open and close tag correctly
        if (closingTag[0] == '/') {
          correctOutput.push_back("<"+closingTag.substr(1)+">");
          correctOutput.push_back("<"+closingTag+">");
        //If closing tag doesn't start with '/' then open and close tag correctly
        }else {
          correctOutput.push_back("<"+closingTag+">");
          correctOutput.push_back("</"+closingTag+">");
        }
      }

    //If only opening tag and data are present
    }else if (!openingTag.empty() && closingTag.empty() && !data.empty()) {
      //Then closing tag is missing and should be corrected
      errors.push_back(error("MISSING_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openingTag,lineNumber));
      correctOutput.push_back("<"+openingTag+">");
      correctOutput.push_back(data);
      correctOutput.push_back("</"+openingTag+">");

    //If only opening tag is present then -> Multi-Attributed tag
    }else if (!openingTag.empty() && closingTag.empty() && data.empty()) {
      bool found = false;

      //Checks if the same opening tag is already present in the vector
      for (int i=0; i<openTagVector.size(); i++) {
        if (openTagVector[i] == openingTag) {
          found = true;
          break;
        }
      }

      if (found) {
        //If a similar opening tag already exists then the old tag should be closed before adding the new one -> Error
        errors.push_back(error("MISSING_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openingTag,lineNumber));
        //Keep closing all child tags till reaching the parent tag
        while (openTagVector.back() != openingTag) {
          correctOutput.push_back("</"+openTagVector.back()+">");
          openTagVector.pop_back();
        }
        //Close the original tag and add the new tag to the output vector
        correctOutput.push_back("</"+openingTag+">");
        correctOutput.push_back("<"+openingTag+">");
      }else {
        //If no similar tag exists then just add it to the vector
        openTagVector.push_back(openingTag);
        correctOutput.push_back("<"+openingTag+">");

      }
    //If only closing tag is present
    }else if (openingTag.empty() && !closingTag.empty()) {
      //If closing tag matches the expected tag to be closed then -> No Error
      if (!openTagVector.empty() && closingTag == "/"+openTagVector.back()) {
        correctOutput.push_back("<"+closingTag+">");
        openTagVector.pop_back();
      //If it doesn't match then -> Error
      }else {
        //Check if there truly exists an opening tag for this closing tag
        bool found = false;
        for (int i=0; i<openTagVector.size(); i++) {
          if (closingTag == "/"+openTagVector[i]) {
            found = true;
            break;
          }
        }
        //If there's an opening tag then all the tags between them haven't been closed -> Add errors and close the tags
        if (found) {
          while (closingTag != "/"+openTagVector.back()) {
            errors.push_back(error("MISSING_CLOSING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + openTagVector.back(),lineNumber));
            correctOutput.push_back("</"+openTagVector.back()+">");
            openTagVector.pop_back();
          }
          correctOutput.push_back("<"+closingTag+">");
          openTagVector.pop_back();
        //If there doesn't exist an opening tag then this closing tag has no opening tag -> Add opening tag right before it
        }else {
          errors.push_back(error("MISSING_OPENING_TAG_AT_LINE: " + to_string(lineNumber) + "FOR_TAG:" + closingTag.substr(1),lineNumber));
          correctOutput.push_back("<"+closingTag.substr(1)+">");
          correctOutput.push_back("<"+closingTag+">");
        }
      }
    }

  }

  //closes the file to reopen in truncation mode
  file.close();
  //clears data inside file
  file.open(path, std::ios::out | std::ios::trunc);
  file.close();
  //reopens the file for data rewrite
  file.open(path);
    if (file.is_open()) {
      for (int i=0; i<correctOutput.size(); i++) {
        file << correctOutput[i] << endl;
      }
    }

    return errors;
}

int main () {

    vector<error> errors = validityCheck_Correction("D:/CSE-Senior1/DSA/CSE331-DSA-Project/input.txt.txt");

    if (errors.empty()) {
      cout << "No errors found" << endl;
    }else {
      while (errors.empty() == false) {
        cout<<errors.back().print_error()<<endl;
        errors.pop_back();
      }
    }

    return 0;
  }

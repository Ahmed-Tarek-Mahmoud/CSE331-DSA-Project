#ifndef TREE_H
#define TREE_H
#include "headers.h"

class attribute{
public:
    string Name , Value;
};

class TreeNode{
public:
    bool hasData , hasError , visited;
    string TagName , TagValue;
    vector<attribute> attributes;
    vector<TreeNode *> children;
    TreeNode * parent;
    TreeNode(string n = "" , string v = ""){
        TagName = n;
        TagValue = v;
        if (TagValue.empty()) hasData = false;
        else hasData = true;
        hasError = false;
        visited = false;
    }
    void addChild(TreeNode *child){
        this->children.push_back(child);
    }
    void addAttribute(attribute &at){
        this->attributes.push_back(at);
    }
    // Pass an Opening Tag To Initialize The node
    void createNode(string Tag) {
        TagName = "";
        string str = "";
        attribute tmp;
        int len = Tag.length();
        int i = 1; // Start after '<'

        // Extract Tag Name
        while (i < len && Tag[i] != ' ' && Tag[i] != '>') {
            TagName += Tag[i++];
        }

        // Skip whitespace after TagName
        while (i < len && Tag[i] == ' ') i++;

        // Extract Attributes
        while (i < len && Tag[i] != '>') {
            // Skip whitespace
            while (i < len && Tag[i] == ' ') i++;

            // Extract Attribute Name
            while (i < len && Tag[i] != '=' && Tag[i] != ' ' && Tag[i] != '>') {
                str += Tag[i++];
            }
            tmp.Name = str;
            str = "";

            // Skip until '='
            while (i < len && Tag[i] != '=') i++;
            if (i < len && Tag[i] == '=') i++;

            // Skip leading quotes or spaces
            char quoteChar = 0;
            if (i < len && (Tag[i] == '"' || Tag[i] == '\'')) {
                quoteChar = Tag[i++];
            }

            // Extract Attribute Value
            while (i < len && Tag[i] != quoteChar && (quoteChar != 0 || Tag[i] != ' ' && Tag[i] != '>')) {
                str += Tag[i++];
            }
            tmp.Value = str;
            str = "";

            // Skip closing quote
            if (i < len && (Tag[i] == quoteChar)) i++;

            // Add the attribute to the node
            this->addAttribute(tmp);
        }
    }


};

class Tree{
private:
    TreeNode *root;
public:
    Tree(){
        root = nullptr;
    }
    void setRoot(TreeNode *node);
    TreeNode * getRoot();
    bool isEmpty();
};

#endif
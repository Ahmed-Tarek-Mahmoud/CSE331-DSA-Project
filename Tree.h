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
    void createNode(string Tag){
        TagName = "";
        string str = "";
        attribute tmp;
        int len = Tag.length();
        for (int i = 1; i < len; ++i) {
            // Extract Tag Name
            while (Tag[i] != ' ' && Tag[i] != '>') TagName += Tag[i++];
            // Extract Attributes
            while (i+1 < len){
                while (Tag[i] == ' ') i++;
                while (Tag[i] != ' ' && Tag[i] != '=') str += Tag[i++];
                tmp.Name = str;
                str = "";
                while (Tag[i] == ' ' || Tag[i] == '=' || Tag[i] == '\'' || Tag[i] == '"' || Tag[i] == '\\') i++;
                while (Tag[i] != '\'' && Tag[i] != '"' && Tag[i] != '\\')	str += Tag[i++];
                tmp.Value = str;
                i++;
                this->addAttribute(tmp);
            }
        }
    }

};

class Tree{
private:
    TreeNode *root;
public:
    Tree();
    void setRoot(TreeNode *node);
    TreeNode * getRoot();
    bool isEmpty();
};

#endif
#ifndef CONVERT_H
#define CONVERT_H
#include "headers.h"
#include "Tree.h"

//converts xml tree to json
string convertToJSON(TreeNode *node, int indentLevel);

string treeToJson(Tree *tree); 

string convertSiblings(TreeNode *node, int indentLevel);

string createIndent(int level);

#endif
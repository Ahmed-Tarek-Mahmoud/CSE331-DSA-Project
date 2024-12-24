#ifndef POSTGRAPH_H
#define POSTGRAPH_H
using namespace std;
#include <string>
#include <vector>
#include <queue>
#include "Tree.h"

typedef struct {
    int userid;
    string topic;
    string body;
}post;

inline vector<vector<post*>> postGraph;

void addPosts(TreeNode *posts,int id);

void postGraphParse(TreeNode* root);


#endif
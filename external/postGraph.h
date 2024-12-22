#ifndef POSTGRAPH_H
#define POSTGRAPH_H

#include "headers.h"
#include <string>
#include <vector>
#include <queue>
#include "Tree.h"

typedef struct {
    int userid;
    string topic;
    string body;
}post;

vector<vector<post>> postGraph;

void addPosts(TreeNode *posts,int id);

void postGraphParse(TreeNode* root);


#endif
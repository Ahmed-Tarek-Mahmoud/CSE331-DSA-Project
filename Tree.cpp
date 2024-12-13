#include "Tree.h"


TreeNode *Tree::getRoot() {
    return root;
}

bool Tree::isEmpty() {
    return root == nullptr;
}

void Tree::setRoot(TreeNode *node) {
    this->root = node;
}



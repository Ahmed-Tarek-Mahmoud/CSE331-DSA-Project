#include "Tree.h"

Tree::Tree() {
    root = nullptr;
}

TreeNode *Tree::getRoot() {
    return root;
}

bool Tree::isEmpty() {
    return root == nullptr;
}

void Tree::setRoot(TreeNode *node) {
    this->root = node;
}



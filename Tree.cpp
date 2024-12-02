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


void Tree::printTreePrettified(TreeNode* node, int depth = 0) {
    if (!node) return;

    // Indent based on depth and print the tag name
    cout << string(depth * 4, ' ') << "<" << node->TagName;

    //check if there any attributes for the tag name
    if (!node->attributes.empty()) {
        for (attribute att : node->attributes) {
            cout << " " << att.Name << "=\"" << att.Value << "\"";
        }
        cout << ">";
    }
    else {
        cout << ">";
    }

    //for Large Text: start newline and indentation before printing as in body Tagname
    if (node->TagValue.length() > 25) {
        cout << "\n" << string(depth * 4, ' ');
    }

    //for small Text: Print Tagvalue directly 
    if (!node->TagValue.empty()) {
        cout << node->TagValue;
    }
    else {
        cout << "\n";
    }

    // Recursively print child nodes
    for (TreeNode* child : node->children) {
        printTreePrettified(child, depth + 1);
    }

    if (node->TagValue.length() > 25) {
        cout << "\n" << string(depth * 4, ' ') << "</" << node->TagName << ">" << endl;
    }
    else if (!node->TagValue.empty()) {
        cout << "</" << node->TagName << ">" << endl;
    }
    else {
        cout << string(depth * 4, ' ') << "</" << node->TagName << ">" << endl;
    }

}


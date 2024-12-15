#include "pretty.h"

void prettifyprint(TreeNode* node, int depth) {
    if (!node) return;

    // Indent based on depth and print the tag name
    cout << string(depth * 4, ' ') << "<" << node->TagName;

    if (!node->attributes.empty()) {
        for (attribute att : node->attributes) {
            cout << " " << att.Name << "=\"" << att.Value << "\"";
        }
        cout << ">";
    }
    else {
        cout << ">";
    }

    if (node->TagValue.length() > 25) {
        cout << "\n" << string(depth * 4, ' ');
    }

    if (!node->TagValue.empty()) {
        cout << node->TagValue;
    }
    else {
        cout << "\n";
    }

    // Recursively print child nodes
    for (TreeNode* child : node->children) {
        prettifyprint(child, depth + 1);
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
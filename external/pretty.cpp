#include "pretty.h"

void prettifyprint(TreeNode* node, int depth) {
    if (!node) return;

    // Indent based on depth and print the tag name
    cout << string(depth * 4, ' ') << "<" << node->TagName;

    // Print attributes
    if (!node->attributes.empty()) {
        for (attribute att : node->attributes) {
            cout << " " << att.Name << "=\"" << att.Value << "\"";
        }
    }
    cout << ">";

    // Print the TagValue with proper formatting
    if (node->TagValue.length() > 25) {
        cout << "\n" << string((depth) * 4, ' ') << node->TagValue;
        cout << "\n" << string(depth * 4, ' ');
    } else if (!node->TagValue.empty()) {
        cout << node->TagValue;
    }

    // Recursively print child nodes
    if (!node->children.empty()) {
        cout << "\n"; // Add a newline before printing children
        for (TreeNode* child : node->children) {

            prettifyprint(child, depth + 1);
        }
        cout<< string(depth * 4, ' '); // Align closing tag properly

    }

    // Print closing tag
    cout << "</" << node->TagName << ">" << endl;
}

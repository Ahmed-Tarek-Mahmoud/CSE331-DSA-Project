#include "Convert.h"
string createIndent(int level) {
    string indent = "";
    for (int i = 0; i < level; ++i) {
        indent += "\t";  // Use tab character for indentation
    }
    return indent;
}

string convertSiblings(TreeNode *node, int indentLevel) {
    string str = "";
    string indent = createIndent(indentLevel);

    if (node->children.size() == 0) {
        str += "\"" + node->TagValue + "\"";
    } else {
        str += "{\n";
        for (int i = 0; i < node->children.size(); i++) {
            str += indent + "\t";  // Add a tab for each child
            if (i != node->children.size() - 1)
                str += convertToJSON(node->children[i], indentLevel + 1) + ",\n";
            else
                str += convertToJSON(node->children[i], indentLevel + 1) + "\n";
        }
        str += indent + "}";  // Add closing brace with the same indent level
    }
    return str;
}
string convertToJSON(TreeNode *node, int indentLevel) {
    string str = "";
    string indent = createIndent(indentLevel);

    if (node->children.size() == 0) {
        str += "\"" + node->TagName + "\": \"" + node->TagValue + "\"";
    } else {
        if (node->children.size() == 1 || node->children[0]->TagName != node->children[1]->TagName) {
            str += "\"" + node->TagName + "\": {\n";
            for (int i = 0; i < node->children.size(); i++) {
                str += indent + "\t";  // Add tab for each child
                if (i != node->children.size() - 1)
                    str += convertToJSON(node->children[i], indentLevel + 1) + ",\n";
                else
                    str += convertToJSON(node->children[i], indentLevel + 1) + "\n";
            }
            str += indent + "}";  // Closing brace with the same indent level
        } else {
            str += "\"" + node->TagName + "\": [\n";
            for (int i = 0; i < node->children.size(); i++) {
                str += indent + "\t";  // Add tab for each sibling
                if (i != node->children.size() - 1)
                    str += convertSiblings(node->children[i], indentLevel + 1) + ",\n";
                else
                    str += convertSiblings(node->children[i], indentLevel + 1) + "\n";
            }
            str += indent + "]";  // Closing square bracket with the same indent level
        }
    }
    return str;
}

string treeToJson(Tree *tree) {
    if (!tree || tree->isEmpty()) return "{}";
    return "{\n\t" + convertToJSON(tree->getRoot(), 1) + "\n}";  // Start indentation at level 1
}



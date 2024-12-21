#include "Convert.h"
string createIndent(int level) {
    string indent = "";
    for (int i = 0; i < level; ++i) {
        indent += "  ";  // Use tab character for indentation
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
            str += indent + "  ";  // Add a tab for each child
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
        while(!node->TagValue.empty() && (node->TagValue.back()==' ' || node->TagValue.back()=='\n')) node->TagValue.pop_back();
        str += "\"" + node->TagName + "\": \"" + node->TagValue + "\"";
    } else {
        if (node->children.size() == 1 || node->children[0]->TagName != node->children[1]->TagName) {
            str += "\"" + node->TagName + "\": {\n";
            for (int i = 0; i < node->children.size(); i++) {
                str += indent + "  ";  // Add tab for each child
                if (i != node->children.size() - 1)
                    str += convertToJSON(node->children[i], indentLevel + 1) + ",\n";
                else
                    str += convertToJSON(node->children[i], indentLevel + 1) + "\n";
            }
            str += indent + "}";  // Closing brace with the same indent level
        } else {
            str += "\"" + node->TagName + "\": [\n";
            for (int i = 0; i < node->children.size(); i++) {
                str += indent + "  ";  // Add tab for each sibling
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

string treeToJson(Tree tree) {
    if (tree.isEmpty()) return "{}";
    return "{\n  " + convertToJSON(tree.getRoot(), 1) + "\n}";  // Start indentation at level 1
}



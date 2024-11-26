#include "..\tree.h"
#include "treeparse.h"

TreeNode* parseNode(const string &s,int &i) {
    TreeNode* t;
    for(;i<s.length();i++) {
        if(s[i]=='<' && s[i+1]!='/') { // search for start of open tag
            TreeNode *currentNode=new TreeNode("","");
            int j=i;
            while(s[j]!='>') j++; // move till end of open tag
            currentNode->createNode(s.substr(i,j-i+1));
            i=j+1;
            while(s[j]!='<') j++; // move to get tag value
            j--;
            string temp=s.substr(i,j-i+1);
            currentNode->TagValue=temp; // to be edited lma tarek y5leh private
            while(s[j]!='<') j++;
            while( j<s.length() && (s[j]!='<' || s[j+1]!='/') ) {
                if(s[j+1]!='/')
                    currentNode->addChild(parseNode( s,j ) ); // recursion to get children
            }
            j++; // advance one step to pass '<' so that closing tag is not the same for all open tags
            while(j<s.length() && s[j]!='<') j++; // move to get next tag

            i=j; // return new index reached to be O(n)
            return currentNode;


        }
    }

}

Tree parseTree(const string &s){
    Tree *tr= new Tree();
    int i=0;
    tr->setRoot(parseNode(s,i));
    return *tr;
}

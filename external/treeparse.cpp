#include "tree.h"
#include "treeparse.h"

using namespace std;
TreeNode* parseNode(const string &s,int &i) {
    TreeNode* t;
    for(;i<s.length();i++) {
        if(s[i]=='<' && s[i+1]!='/') { // search for start of open tag
            TreeNode *currentNode=new TreeNode("","");
            int j=i;
            while(s[j]!='>') j++; // move till end of open tag
            currentNode->createNode(s.substr(i,j-i+1));
            i=j+1;
            while(s[i] == ' ' || s[i] == '\n') i++; // tarek1
            while(s[j]!='<') j++; // move to get tag value
            j--;
            while(j > i && s[j] == '\n') j--; // tarek2
            string temp=s.substr(i,j-i+1);
            string newtemp;
            //trim spaces from TagValue
            int k;
            for(k=0;temp[k]==' ';k++)
                ;
            newtemp=temp.substr(k,temp.length()-k);
            k=newtemp.length()-1;
            for(;newtemp[k]==' ';k--)
                ;
            newtemp=newtemp.substr(0,k+1);
            currentNode->TagValue=newtemp; // to be edited lma tarek y5leh private
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
    return nullptr;
}

Tree parseTree(const string &s){
    Tree *tr= new Tree();
    int i=0;
    tr->setRoot(parseNode(s,i));
    return *tr;
}

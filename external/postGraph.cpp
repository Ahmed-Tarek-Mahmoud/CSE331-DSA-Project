#include "postGraph.h"

void addPosts(TreeNode *posts,int id){
    postGraph.push_back(vector<post*>());  // after reaching posts tag make new posts vector for this user
    for(auto p:posts->children){ // loop through all posts
        if(p->TagName=="post"){
            vector<string> topic;
            string body;
            for(auto t:p->children){ // get post topic and body
                if(t->TagName=="topics"){
                    for(auto tpc:t->children)
                      if(tpc->TagName=="topic"){
                          topic.push_back(tpc->TagValue);
                      }
                }
                if(t->TagName=="body")
                    body=t->TagValue;
                if(topic!="" && body!="")
                    break;
            }
            post* userpost= new post();
            userpost->userid=id;
            userpost->topic=topic;
            userpost->body=body;

            postGraph.back().push_back(userpost); // add post to graph
        }
    }

}

void postGraphParse(TreeNode* root){
    if(root==nullptr)
        return;
    TreeNode* users=nullptr;
    queue<TreeNode*> myqueue;
    myqueue.push(root);
    do{ // BFS to get <users> tag
        users=myqueue.front();
        if(users->TagName=="users")
            break;
        myqueue.pop();
        for(auto n:users->children)
            myqueue.push(n);
    }while(users!=nullptr);
    TreeNode* user=nullptr;
    // the many if conditions in following code is to handle cases where
    for(auto n:users->children){ // loop through all users
        user=n;
        if(user->TagName=="user"){ // loop on users info to get its id and post
            int userId;
            for(auto u:user->children){
                if(u->TagName=="id") // get user id
                    userId=stoi(u->TagValue);
                if(u->TagName=="posts"){ // get posts
                    addPosts(u,userId); // add posts tp postGraph
                }
            }
        }
    }
}

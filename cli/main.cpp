#include <cstring>
#include "../external/headers.h"
#include "../external/Tree.h"
#include "../external/treeparse.h"
#include "../external/pretty.h"
#include "../external/Convert.h"
#include "../external/minifier.hpp"
#include "../external/Validity.h"
#include "../external/CompDec.h"
#include "../external/graph.hpp"
#include "../external/graphParsing.hpp"
#include "../external/socialGraph.h"
#include "../external/graphAnalysis.h"
#include "../external/postGraph.h"
#include "../external/Search.h"
#include "set"


using namespace std;
int main(int argc, char *argv[]) {
    // main program

//    if (strcmp(argv[1] , "format") == 0 && strcmp(argv[2] , "-i") == 0){
//        ifstream file(argv[3]);
//        if (!file.is_open()) {
//            // print error message and return
//            cerr << "Failed to open file: " << argv[3] << endl;
//
//            return 1;
//        }
//
//        string line , totalXML = "";
//        while (getline(file, line)) {
//            totalXML += line;
//        }
//        file.close();
//        Tree myTree;
//        myTree = parseTree(totalXML);
//
//        if (strcmp(argv[4] , "-o") != 0){
//            cout<<"Command not recognized\n";
//            return 1;
//        }
//        FILE *fp = freopen(argv[5] , "w", stdout);
//        prettifyprint(myTree.getRoot() , 0);
//        fclose(fp);
//    }
//    else if (strcmp(argv[1] , "json") == 0 && strcmp(argv[2] , "-i") == 0){
//        ifstream file(argv[3]);
//        if (!file.is_open()) {
//            // print error message and return
//            cerr << "Failed to open file: " << argv[3] << endl;
//
//            return 1;
//        }
//
//        string line , totalXML = "";
//        while (getline(file, line)) {
//            totalXML += line;
//        }
//        file.close();
//        Tree myTree;
//        myTree = parseTree(totalXML);
//
//        if (strcmp(argv[4] , "-o") != 0){
//            cout<<"Command not recognized\n";
//            return 1;
//        }
//        FILE *fp = freopen(argv[5] , "w", stdout);
//        string json = treeToJson(myTree);
//        cout<<json;
//        fclose(fp);
//    }
//    else if (strcmp(argv[1] , "mini") == 0 && strcmp(argv[2] , "-i") == 0){
//        if (argc < 6){
//            cerr<<"Missing Output File\n";
//            return 1;
//        }
//        minifyXMLFiles(argv[3] , argv[5]);
//    }
//    else if (strcmp(argv[1] , "verify") == 0 && strcmp(argv[2] , "-i") == 0){
//        vector<string> correct;
//        vector<error> erVec = validityCheck_Correction(argv[3] , correct);
//        for(auto &e:erVec) cout<<e.getMessage()<<endl;
//        if (argc > 4){
//            FILE *fp = freopen(argv[5] , "w", stdout);
//            for(auto &s:correct) cout<<s<<endl;
//            fclose(fp);
//        }
//    }
//    else if (strcmp(argv[1] , "compress") == 0 && strcmp(argv[2] , "-i") == 0){
//        ifstream file(argv[3]);
//        if (!file.is_open()) {
//            // print error message and return
//            cerr << "Failed to open file: " << argv[3] << endl;
//
//            return 1;
//        }
//
//        string line , totalXML = "";
//        while (getline(file, line)) {
//            totalXML += line;
//        }
//        file.close();
//        vector<int> cmp;
//        cmp = CompDec::compress(totalXML);
//        if (argc < 6){
//            cerr<<"Missing Output File\n";
//            return 1;
//        }
//        string wr = CompDec::compressed_data_to_string(cmp);
//        CompDec::write_file(argv[5] , wr);
//    }
//    else if (strcmp(argv[1] , "decompress") == 0 && strcmp(argv[2] , "-i") == 0){
//        vector<int> data = CompDec::string_to_compressed_data(CompDec::read_file(argv[3]));
//        string out = CompDec::decompress(data);
//        if (argc < 6){
//            cerr<<"Missing Output File\n";
//            return 1;
//        }
//        CompDec::write_file(argv[5] , out);
//    }

    // Level 2
//    else
        if (strcmp(argv[1] , "most_active") == 0 && strcmp(argv[2] , "-i") == 0){
        pair<int , string> most_active = mostActiveUser(argv[3]);
        cout<<"User ID: "<<most_active.first <<endl;
        cout<<"Username: "<<most_active.second<<endl;
    }else if (strcmp(argv[1] , "most_influencer") == 0 && strcmp(argv[2] , "-i") == 0) {
        pair<int, string> most_inf = mostInfluential(argv[3]);
        cout << "User ID: " << most_inf.first << endl;
        cout << "Username: " << most_inf.second << endl;
    }else if(strcmp(argv[1] , "suggest") == 0 && strcmp(argv[2] , "-i") == 0){
        if (argc < 6){
            cout<<"No matching command"<<endl;
            return 1;
        }
        if (strcmp(argv[4] ,"-id")){
            cout<<"No matching command"<<endl;
            return 1;
        }
        vector<int> ans = suggest(atoi(argv[5]) , argv[3]);
        set<int> sug{ans.begin() , ans.end()};
        cout<<"Suggested: ";
        for(auto i : sug) cout<<i<<" ";
        cout<<endl;
    }else if (strcmp(argv[1] , "search") == 0 && strcmp(argv[2] , "-w") == 0){
        if (argc < 6){
            cout<<"No matching command"<<endl;
            return 1;
        }
        ifstream file(argv[5]);
        if (!file.is_open()) {
            // print error message and return
            cerr << "Failed to open file: " << argv[3] << endl;

            return 1;
        }

        string line , totalXML = "";
        while (getline(file, line)) {
            totalXML += line;
        }
        file.close();
        string key = argv[3];
        Tree mytree = parseTree(totalXML);
        postGraphParse(mytree.getRoot());
        Search search;
        search.generateWords();
        vector<post *> ans = search.searchWord(key);
        for(auto p : ans){
            cout<<"User ID: "<<p->userid<<endl;
            cout<<"Post Topic: "<<p->topic<<endl;
            cout<<"Post Content: \n"<<p->body<<endl;
        }
    }
    return 0;
}

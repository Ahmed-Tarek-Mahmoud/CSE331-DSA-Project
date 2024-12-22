#include <cstring>
#include "../external/headers.h"
#include "../external/Tree.h"
#include "../external/treeparse.h"
#include "../external/pretty.h"
#include "../external/Convert.h"
#include "../external/minifier.hpp"
#include "../external/Validity.h"
#include "../external/CompDec.h"


using namespace std;
int main(int argc, char *argv[]) {
    // main program

    if (strcmp(argv[1] , "format") == 0 && strcmp(argv[2] , "-i") == 0){
        ifstream file(argv[3]);
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
        Tree myTree;
        myTree = parseTree(totalXML);

        if (strcmp(argv[4] , "-o") != 0){
            cout<<"Command not recognized\n";
            return 1;
        }
        FILE *fp = freopen(argv[5] , "w", stdout);
        prettifyprint(myTree.getRoot() , 0);
        fclose(fp);
    }
    else if (strcmp(argv[1] , "json") == 0 && strcmp(argv[2] , "-i") == 0){
        ifstream file(argv[3]);
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
        Tree myTree;
        myTree = parseTree(totalXML);

        if (strcmp(argv[4] , "-o") != 0){
            cout<<"Command not recognized\n";
            return 1;
        }
        FILE *fp = freopen(argv[5] , "w", stdout);
        string json = treeToJson(myTree);
        cout<<json;
        fclose(fp);
    }
    else if (strcmp(argv[1] , "mini") == 0 && strcmp(argv[2] , "-i") == 0){
        if (argc < 6){
            cerr<<"Missing Output File\n";
            return 1;
        }
        minifyXMLFiles(argv[3] , argv[5]);
    }
    else if (strcmp(argv[1] , "verify") == 0 && strcmp(argv[2] , "-i") == 0){
        vector<string> correct;
        vector<error> erVec = validityCheck_Correction(argv[3] , correct);
        for(auto &e:erVec) cout<<e.getMessage()<<endl;
        if (argc > 4){
            FILE *fp = freopen(argv[5] , "w", stdout);
            for(auto &s:correct) cout<<s<<endl;
            fclose(fp);
        }
    }
    else if (strcmp(argv[1] , "compress") == 0 && strcmp(argv[2] , "-i") == 0){
        ifstream file(argv[3]);
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
        vector<int> cmp;
        cmp = CompDec::compress(totalXML);
        if (argc < 6){
            cerr<<"Missing Output File\n";
            return 1;
        }
        string wr = CompDec::compressed_data_to_string(cmp);
        CompDec::write_file(argv[5] , wr);
    }
    else if (strcmp(argv[1] , "decompress") == 0 && strcmp(argv[2] , "-i") == 0){
        vector<int> data = CompDec::string_to_compressed_data(CompDec::read_file(argv[3]));
        string out = CompDec::decompress(data);
        if (argc < 6){
            cerr<<"Missing Output File\n";
            return 1;
        }
        CompDec::write_file(argv[5] , out);
    }

    // Level 2

    return 0;
}

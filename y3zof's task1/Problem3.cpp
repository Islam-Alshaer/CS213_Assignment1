#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<string> split(string target,string delimt) {

    vector<string> answer;
    string str = "";
    target += delimt;
    int sztarget = target.size();
    int szlimit = delimt.size();
    while (!target.empty()){
        int pos = target.find(delimt);
        for (int j = 0; j < pos; ++j) {
            str += target[j];
        }
        answer.push_back(str);
        int erase = pos + szlimit ;
        for (int j = 0; j < (erase); ++j) {
            target.erase(target.begin());
        }
        str = "";
    }

    if (!target.empty()){
        answer.push_back(target);
    }

    return answer;
}


int main(){
    string targetiput , lmtiput ;
    cout << "Welcome to split string program :)" << endl;
    cout << "Please enter the string you want to split." << endl;
    getline(cin,targetiput);
    cout << "please enter the string delimiter you want the program to work with." << endl;
    getline(cin,lmtiput);
    vector <string> myVector = split(targetiput, lmtiput);
    for (auto& it : myVector) {
        cout << it << ".";
    }
}

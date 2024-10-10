#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include "cmath"
#include <fstream>
#include <map>
using namespace std;

map <string, int> mp = {{"account", 50}, {"password", 50}, {"login", 50}, {"verify", 50}, {"urgent", 50}, {"alert", 50}, {"payment", 50}, {"security", 50}, {"suspended", 50}, {"update", 50}, {"confirm", 50}, {"failure", 40}, {"blocked", 40}, {"access", 40}, {"notification", 40}, {"request", 40}, {"action", 40}, {"error", 40}, {"service", 40}, {"deactivated", 30}, {"download", 30}, {"support", 30}, {"expired", 30}, {"bank", 30}, {"unusual", 30}, {"authorize", 20}, {"detected", 20}, {"renew", 20}, {"credentials", 20}};


void phishingscamScore(string txtname){

    fstream Email;string str;
    Email.open(txtname,ios::in);
    int Score = 0;
    if (!Email){
        cout << "Error" << endl;
    }else{
        while (!Email.eof()){
            Email>>str;
            for (char& c : str) {
                c = tolower(c);
            }
            if (mp.find(str) != mp.end()){
                Score += mp[str];
            }
        }
    }
    cout << "The phishing score of the email is :  " << Score << endl;
    return;
}

int main() {

    string txt;
    cout << "Please enter the txt file's name that contains the email you want to check:" << endl;
    cin >> txt;
    phishingscamScore(txt);

}


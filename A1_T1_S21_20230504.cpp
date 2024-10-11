// File: A1_T1_S21_20230504.cpp
// Purpose: Handle some of the problems that might face a human while using his PC.
// Author: Youssef Farid Sayed
// Section: 21
// ID: 20230504
// TA:
// Date: 11 Oct 2024






#include <iostream>
#include <vector>
#include <string.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include "cmath"
#include <fstream>
#include <map>
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

void PrintBinarary (int n){
    if (n > 1){
        PrintBinarary(n/2);
    }
    cout << n % 2 ;
}

void PrintingManyNumbers(string prefix,int k){
    if (k == 0){
        cout << prefix << endl;
        return;
    }else{
        PrintingManyNumbers(prefix + '0', k - 1);
        PrintingManyNumbers(prefix + '1', k - 1);
    }
}

bool TeddyBearGame(int n){

    if (n == 42){
        return true;
    }
    if (n < 42){
        return false;
    }
    if (n%2==0){
        if (TeddyBearGame(n/2)){
            return true;
        }
    }
    if (n%3==0 or n%4==0){
        if (((n % 10)*((n % 100) / 10))!=0){
            if (TeddyBearGame(  n-((n % 10)*((n % 100) / 10))       )){
                return true;
            }
        }
    }
    if (n%5==0){
        if (TeddyBearGame(n-42)){
            return true;
        }
    }
    return false;
}

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

    cout << "Welcome to Y3zof's program :" << endl << endl;
    cout << "For problem 3 (Split) Enter [1] "<<endl;
    cout << "For problem 6 (Binaries) Enter [2] "<<endl;
    cout << "For problem 9 (TeddyBearGame) Enter [3] "<<endl;
    cout << "For problem 12 (PhishingEmailsScorer) Enter [4] "<<endl;
    int inpt ;
    cin >> inpt;
    if (inpt == 1){
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
    if (inpt == 2){
        cout << "Welcome to Numbers programs :)" << endl;
        cout << "Please choose the operation you want to proceed" << endl;
        cout << "for 'One Binary Number' enter '1' for 'Printing Many Numbers' enter '2'" << endl;
        int enter ;
        cin >> enter;
        if (enter == 1){
            int n;
            cout << "Please enter your decimal number" << endl;
            cin >> n ;
            PrintBinarary(n);
        }else{
            cout << "Please enter your prefix string and your suffix number" << endl;
            string str;
            cin >> str;
            int k;
            cin >> k;
            PrintingManyNumbers(str,k);
        }
    }
    if (inpt == 3){
        int n;
        cout << "Please enter the number you want to start the game with :" << endl;
        cin >> n;
        if (TeddyBearGame(n)){
            cout << "True" << endl;
        }else{
            cout << "False" << endl;
        }
    }
    if (inpt == 4){
        string txt;
        cout << "Please enter the txt file's name that contains the email you want to check:" << endl;
        cin >> txt;
        phishingscamScore(txt);
    }

    return 0;
}

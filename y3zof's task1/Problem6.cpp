#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include "cmath"
using namespace std;


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


int main() {
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

    return 0;
}
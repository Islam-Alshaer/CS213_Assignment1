#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include "cmath"
using namespace std;

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

int main(){
    int n;
    cout << "Please enter the number you want to start the game with :" << endl;
    cin >> n;
    if (TeddyBearGame(n)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
}
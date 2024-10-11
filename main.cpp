#include <bits/stdc++.h>
using namespace std;

void speech() {
    cout << "Enter a text speech:\n";
    string in; getline(cin, in);
    string out, word;
    for (char i : in) {
        if(isalpha(i))
            word += i;
        else {
            if(!word.empty()) {
                if(word == "he" || word == "He") {
                    out += word + " or she" + i;
                    word.erase();
                } else if(word == "him" || word == "Him") {
                    out += word + " or her" + i;
                    word.erase();
                }
                else {
                    out += word + i;
                    word.erase();
                }
            }
            else
                out += i;
        }
    }
    if(!word.empty())
        out += word;

    cout << out;
}

int main() {
    speech();

    return 0;
}
/* student name : Islam Waleed Salah
 * Id: 20230062
 * version: 1.0
 * */

#include "iostream"
#include <algorithm>
#include "cctype"

int main(){

    std::cout << "Ahlan ya user ya habibi, entere a sentnece no longer than 100 character:";
    std::string input;
    std::string subinput;
    while(std::getline(std::cin, subinput) and not subinput.empty()){
        input += subinput;
    }

    std::cout << "\"";
    //check first letter
    if(isalpha(input[0]))
        std::cout << (char)toupper(input[0]);
    else
        std::cout << input[0];

    //then we modify the sentence
    for (int i = 1; i < std::min(100, (int)input.length()); ++i) { // maximum lenght is 100
        if(i != std::min(100, (int)input.length())) { //if it's not the last letter
            if ((input[i] == ' ' or input[i] == '\n') and (input[i + 1] == ' ' or input[i + 1] == '\n')) { //if the current letter and the letter after it are space of newline
                continue;
            }
            else{
                std::cout << (char) tolower(input[i]);
            }
        }
        else
            std::cout << input[i];
    }
    std::cout << '\"';
}



/*
test cases:
1-Hello   world
2-hello world
3-hello
  world
4-Normal sentence
5-1 test.
6-Text ends withe spaces      |
7-Capital LETTER in the middle
8-I love Dr.Alramly and his Teaching Assistants.
*/
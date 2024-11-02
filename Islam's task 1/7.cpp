/* student name : Islam Waleed Salah
 * Id: 20230062
 * version: 5.3
 * */
#include "iostream"
#include "vector"
#include "string"

const int size = 5;
std::string solution;

struct dominoT{
    int leftDots;
    int rightDots;
};

std::string sub_answer;
std::vector<bool> is_domino_taken(size, false);

bool FormsDominoChain(std::vector<dominoT> & dominos){ //using backtracking:

    if(solution.length() == (2 * dominos.size())){
        sub_answer = solution;
        return true;
    }

    for (int i = 0; i < size; ++i) {
        // there 2 cases that I don't try
        if(is_domino_taken[i]) // or that the domino is already taken so we can not take it twice
            continue;
        if(!solution.empty() and solution.back() != char(dominos[i].leftDots + '0')) //the right part of the previous one is not like the left part of the new one
        {
            continue;
        }

        //try
        solution += std::to_string(dominos[i].leftDots) + std::to_string(dominos[i].rightDots);
        is_domino_taken[i] = true;

        //recurse
        if(FormsDominoChain(dominos))
            return true;

        //undo
        for (int j = 0; j < 2; ++j)
            solution.pop_back();
        is_domino_taken[i] = false;

    }
    return false;

}

int main(void){

    //our basic varibles
    std::string s;
    std::vector<dominoT> v(size);
    v[0] = dominoT{1, 4};
    v[1] = dominoT{2, 6};
    v[2] = dominoT{4, 4};
    v[3] = dominoT{6, 1};
    v[4] = dominoT{4, 3};

    FormsDominoChain(v);
    std::string final_answer{sub_answer[0]};
    for (int i = 1; i < sub_answer.size(); ++i) {
        if(i % 2 != 0) // i & 1 is more optimized
            final_answer += '|';
        final_answer += sub_answer[i];
        if(i % 2 != 0)
            final_answer += ' ';
    }
    std::cout << final_answer;

}
//26 61 14 44 43
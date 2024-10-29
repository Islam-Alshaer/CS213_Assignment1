#pragma once
#include <string>
#include "Register.h"
using namespace std;

class ALU {
public:
    int hexToDec(int indxReg, Register& regist);
    string decToHex(int dec);
    string hexToBinary(int indxReg, Register& k);
    void add(int indx1, int indx2, int indx3, Register& k);
};

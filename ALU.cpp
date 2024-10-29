#include "ALU.h"
#include "Register.h"
#include <map>
#include <cmath>
using namespace std;

map<char, string> hexAndDecMap = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"}
};

int ALU::hexToDec(int indxReg, Register& regist) {
    string l = regist.getCell(indxReg);
    int dec = 0;
    for(int i = 0; i < 2; i++) {
        dec += pow(16, 1 - i) * int(l[i]);
    }
    return dec;

}
string ALU::decToHex(int dec) {
    if (dec == 0)
        return "0";

    string hex;
    while (dec > 0) {
        int remainder = dec % 16;
        if (remainder < 10) {
            hex += char(remainder); // Convert to character '0'-'9'
        } else {
            hex = char(remainder - 10 + 'A') + hex; // Convert to character 'A'-'F'
        }
        dec /= 16;
    }

    return hex;
}

string ALU::hexToBinary(int indxReg, Register &k) {
    string l = k.getCell(indxReg);
    string binary;
    for(int i = 0; i < 2; i++) {
        binary += hexAndDecMap[l[i]];
    }
    return binary;
}


void ALU::add(int indx1, int indx2, int indx3, Register &k) {
    int num1 = hexToDec(indx2, k), num2 = hexToDec(indx3, k);
    string total = decToHex(num1 + num2);
    k.setCell(indx1, total);

}



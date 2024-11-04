#include "ALU.h"
#include "Register.h"
#include <map>
#include <cmath>
#include<iostream>
#include <algorithm>
using namespace std;

ALU::ALU(Memory &machine_memory, Register &machine_register) :
    machine_memory(&machine_memory), machine_register(&machine_register){

}

map<char, string> hexAndBinMap = {
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

int ALU::hexToDec(string hex) {
    int dec = stoi(hex, 0, 16);
    return dec;
}

string ALU::decToHex(int dec) {
    if (dec == 0)
        return "0";
    string hex;
    while (dec > 0) {
        int remainder = dec % 16;
        if (remainder < 10) {
            char c = remainder + '0';
            hex += c;
        } else {
            char c = remainder - 10 + 'A';
            hex += c;
        }
        dec /= 16;
    }
    reverse(hex.begin(), hex.end());
    return hex;
}

string ALU::hexToBin(string hex) {
    string binary;
    for(char i : hex) {
        binary += hexAndBinMap[i];
    }
    return binary;
}
string ALU::binToHex(string bin) {
    string bin1 = bin.substr(0, 4), bin2 = bin.substr(3);
    for(auto i : hexAndBinMap) {
        if(i.second == bin1)
            bin1 = i.first;
        if(i.second == bin2)
            bin2 = i.first;
    }
    return bin1 + bin2;
}

void ALU::add_twos_complement(int R, int S, int T){
    int content_of_S = stoi(machine_register->getCell(S), 0, 16);
    string s = "FF";
    cout << stoi(s, 0, 16);
}

void ALU::add_float_representation(int R, int S, int T) {

}

void ALU::bitwiseAND(int R, int S, int T) {
    Register reg;
    string r, s = reg.getCell(S), t = reg.getCell(T);
    s = hexToBin(s), t = hexToBin(t);

    for(int i = 0; i < 8; i++) {
        if(s[i] == t[i]) {
            if(s[i] == '1')
                r += s[i];
        }
        else
            r += "0";
    }

    r = binToHex(r);
    reg.setCell(R, r);
}

void ALU::bitwiseXOR(int R, int S, int T) {
    Register reg;
    string r, s = reg.getCell(S), t = reg.getCell(T);
    s = hexToBin(s), t = hexToBin(t);

    for(int i = 0; i < 8; i++) {
        if(s[i] == t[i]) {
            r += "0";
        }
        else
            r += "1";
    }

    r = binToHex(r);
    reg.setCell(R, r);
}



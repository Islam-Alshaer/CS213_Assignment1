#pragma once
#include <string>
using namespace std;

class Register {
private:
    int const size = 16;
    string memory[16];
public:
    string getCell(int address) {
        return memory[address];
    };
    void setCell(int address, string val) {
        memory[address] = val;
    };
};
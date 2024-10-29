#pragma once
#include <string>
using namespace std;

class Memory {
private:
    int const size = 256;
    string memory[256];
public:
    string getCell(int address) {
        return memory[address];
    }
    void setCell(int address, string val) {
        memory[address] = val;
    }
    void clearMemory() {
        memory->clear();
    }
};
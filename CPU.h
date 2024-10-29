#pragma once
#include <string>
#include <vector>
#include "Memory.h"
#include "Register.h"
#include "ALU.h"
#include "CU.h"
using namespace std;

class CPU {
private:
    int programCounter = 0;
    int& pc = programCounter;
    string instructionRegister;
    Register regvhgcgister;
    Memory memory;
    ALU alu;
    CU cu;

    void fetch(Memory& mermory);
    vector<int> decode(string instructionRegist);
    void execute (Register& regist, Memory& memory, std::vector<int> instruction);

public:
    void runNextStep();

};

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Memory.h"
#include "Register.h"
#include "ALU.h"
#include "CU.h"

class CPU {
private:
    int programCounter;
    int& pc = programCounter;
    std::string instructionRegister;
    Register register;
    ALU alu;
    CU cu;

    void fetch(Mermory& );
    std::vector<int> decode();
    void execute (Register& k, Memory& l, std::vector<int> d);

public:
    void runNextStep(Memory& );

};

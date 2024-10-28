#pragma once
#include "Memory.h"
#include "Register.h"
#include "ALU.h"

class CU {
public:
    void load(int indxReg, int indxMemory, Register& l, Memory& k);
    void load(int indxReg, int val, Register& l);
    void store(int indxReg, int indxMemory, Register& l, Memory& k);
    void move(int indxReg1, int indxReg2, Register& k);
    void jump(int indxReg, int indxMemory, Register& k, int & PC);
    void halt();
    bool isValid(std::string instruction);
};
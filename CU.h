#pragma once
#include "Memory.h"
#include "Register.h"
#include "ALU.h"

class CU {
public:
    void load(int indxReg, int indxMemory, Register& regist, Memory& memory);
    void load(int indxReg, string val, Register& regist);
    void store(int indxReg, int indxMemory, Register& regist, Memory& memory);
    void move(int indxReg1, int indxReg2, Register& regist);
    void jump(int indxReg, int indxMemory, Register& regist, int & PC);
    void halt(Register& regist, Memory& memory, int& PC);
    bool isValid(std::string instruction);
};
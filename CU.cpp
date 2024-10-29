#include "CU.h"
#include "CPU.h"
#include "ALU.h"
#include "Memory.h"
#include "Register.h"
#include <regex>
using namespace std;

void CU::load(int indxReg, int indxMemory, Register &regist, Memory &memory) {
    regist.setCell(indxReg, memory.getCell(indxMemory));
}

void CU::load(int indxReg, string val, Register &regist) {
    regist.setCell(indxReg, val);
}

void CU::store(int indxReg, int indxMemory, Register &regist, Memory &memory) {
    memory.setCell(indxMemory, regist.getCell(indxReg));
}

void CU::move(int indxReg1, int indxReg2, Register &regist) {
    regist.setCell(indxReg2, regist.getCell(indxReg1));
}

void CU::jump(int indxReg, int indxMemory, Register &regist, int &PC) {
    if(regist.getCell(indxReg) == regist.getCell(00)) {
        PC = indxMemory;
    }
}

void CU::halt(Register& regist, Memory& memory, int& PC) {
    regist.clearMemory();
    memory.clearMemory();
    PC = 0;
}

bool CU::isValid(std::string instruction) {
    regex patten("^[1-6BC]{1}[0-9A-F]{3}$");
    if(!regex_match(instruction, patten))
        return false;
}


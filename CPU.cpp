#pragma once
#include "CPU.h"

void CPU::fetch(Memory &mermory) {
    for(int i = 0; i < 2; i++) {
        instructionRegister += memory.getCell(pc);
        runNextStep();
    }
}

void CPU::runNextStep() {
    pc++;
}

vector<int> CPU::decode(string instructionRegist) {
    char opCode = instructionRegister[0];
    switch (opCode) {
        case '1' : {
            string memory = instructionRegister.substr(2);
            int indxMem = alu.hexToDec();
            cu.load(1, )
        }
    }
}

void CPU::execute(Register &regist, Memory &memory, std::vector<int> instruction) {

}

#pragma once
#include <string>
#include "Register.h"
#include "Memory.h"
using namespace std;

class ALU {
private:
    Memory* machine_memory;
    Register* machine_register;
public:
    ALU(Memory &machine_memory, Register &machine_register);
    void add_twos_complement(int R, int S, int T);
    void add_float_representation(int R, int S, int T);
    void BitWise_OR(int R, int S, int T);
};

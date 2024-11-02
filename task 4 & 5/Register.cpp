#include "Register.h"

Register::Register() {
    fill(register_cells, register_cells + 16, "0");
}

string Register::getCell(int address) const{
    return register_cells[address];
}

void Register::setCell(const int &address, const string &val) {
    register_cells[address] = val;
}

void Register::clearMemory() {
    register_cells->clear();
}
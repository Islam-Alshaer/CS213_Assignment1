#include "Register.h"
#include "vector"

Register::Register() {
    for (int i = 0; i < 16; ++i) {
        register_cells.push_back("00");
    }
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
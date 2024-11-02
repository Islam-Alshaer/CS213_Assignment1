#include "Memory.h"

Memory::Memory(){
    fill(memory_cells, memory_cells + 256, "0");
}

void Memory::clearMemory() {
    for (int i = 0; i <= 255; ++i) {
        this->setCell(i, "00");
    }
}

string Memory::getCell(const int &address) const {
    return memory_cells[address];
}

void Memory::setCell(const int &address, const string &val) {
    memory_cells[address] = val;
}

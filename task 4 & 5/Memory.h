#pragma once
#include <string>

using namespace std;

class Memory {
private:
    string memory_cells[256];

public:
    Memory();
    string getCell(const int &address) const;
    void setCell(const int &address, const string &val);
    void clearMemory();
};
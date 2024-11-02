#pragma once
#include <string>
#include "algorithm"
using namespace std;

class Register {
private:
    string register_cells[16];
public:
    Register();
    string getCell(int address) const;
    void setCell(const int &address, const string &val);
    void clearMemory();
};
#pragma once
#include <string>
#include "algorithm"
using namespace std;

class Register {
private:
    vector<string> register_cells;
public:
    Register();
    string getCell(int address) const;
    void setCell(const int &address, const string &val);
    void clearMemory();
};
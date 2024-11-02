#ifndef TASK3_MEMORY_H
#define TASK3_MEMORY_H

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


#endif //TASK3_MEMORY_H

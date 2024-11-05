#ifndef TASK3_MEMORY_H
#define TASK3_MEMORY_H

#include <string>
#include "vector"

using namespace std;

class Memory {
private:
    vector<string> memory_cells;

public:
    Memory();
    string getCell(const int &address) const;
    void setCell(const int &address, string val);
    void clearMemory();
};


#endif //TASK3_MEMORY_H

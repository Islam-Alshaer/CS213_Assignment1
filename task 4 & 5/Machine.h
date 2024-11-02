
#ifndef TASK3_MACHINE_H
#define TASK3_MACHINE_H
#include "CPU.h"
#include "iostream"
using namespace std;


class Machine {

private:
    CPU processor;
    Memory memory;
    void print_register() const;
    void print_memory() const;
    void store_instruction(string &insturction);
public:
    Machine();
    void load_file_into_memory(ifstream program_file);
    void display_state();
    void run_single_step();
    void complete_execution();
};


#endif //TASK3_MACHINE_H
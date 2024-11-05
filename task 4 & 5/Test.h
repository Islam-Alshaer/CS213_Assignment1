#ifndef TASK_4___5_TEST_H
#define TASK_4___5_TEST_H
#include "Machine.h"
#include "ALU.h"
#include "CPU.h"
#include "CU.h"
#include "Memory.h"
#include "Register.h"
#include "fstream"


class Test {
private:
    fstream logfile;
public:
    void setLogfile(const fstream &logfile);

private:
    void log_test(bool pass, const string &testname);
public:
    Test(const string &log_file_name);
    void test_memory_set_cell(int address, string content);
    void test_clear_memory(int address, string value);

};


#endif //TASK_4___5_TEST_H

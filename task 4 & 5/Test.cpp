#include "Test.h"
#include "iostream"

using namespace std;

Test::Test(const std::string &log_file_name) {
    logfile.open(log_file_name, ios::in | ios::out);
}

void Test::log_test(bool pass, const string &testname) {
    logfile << testname;
    if(pass)
        logfile << ": pass";
    else
        logfile << ": fail";
    logfile << endl;
}

void Test::test_memory_set_cell(int address, string content) {

    Memory memory;
    memory.setCell(address, content);
    string cell = memory.getCell(address);
    string testname = "test_memory_address_:_" + to_string(address) + "_content_:" + content;
    if(cell == content)
        log_test(true, testname);
    else
        log_test(false, testname);

}


void Test::test_clear_memory(int address, string value) {
    Memory memory;
    memory.setCell(address, value);
    memory.clearMemory();
    string testname = "test_clear_memory_";

    //check all elements
    bool all_are_cleared = true;
    for (int i = 0; i <= 255; ++i) {
        if(memory.getCell(i) != "00")
            all_are_cleared = false;
    }
    if(all_are_cleared)
        log_test(true, testname);
    else
        log_test(false, testname);
}


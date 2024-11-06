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


void Test::test_register_set_cell(int address, std::string content) {

    Register aRegister;
    aRegister.setCell(address, content);
    string cell = aRegister.getCell(address);
    string testname = "test_register_address_:_" + to_string(address) + "_content_:" + content;
    if(cell == content)
        log_test(true, testname);
    else
        log_test(false, testname);
}

void Test::test_clear_register(int address, std::string value) {

    Register aRegister;
    aRegister.setCell(address, value);
    aRegister.clearRegister();
    string testname = "test_clear_register_";

    //check all elements
    bool all_are_cleared = true;
    for (int i = 0; i <= 15; ++i) {
        if(aRegister.getCell(i) != "00")
            all_are_cleared = false;
    }

    if(all_are_cleared)
        log_test(true, testname);
    else
        log_test(false, testname);
}



void Test::test_cu_load1(int registeraddress, string register_value, int memoryaddress, string memory_value) {

    Register my_register;
    Memory my_memory;
    CU controlunit(my_memory, my_register);
    my_register.setCell(registeraddress, register_value);
    my_memory.setCell(memoryaddress, memory_value);
    controlunit.Load_register_with_value_in(registeraddress, memoryaddress);

    //checking
    string testname = "test_cu_load_1_" + to_string(registeraddress) + "_" + register_value + "_" + to_string(memoryaddress) + "_" + memory_value;
    if(my_register.getCell(registeraddress) == my_memory.getCell(memoryaddress))
        log_test(true, testname);
    else
        log_test(false, testname);

}


void Test::test_cu_load2(int registeraddress, string valuebefore, string valueafter) {
    //constructing needed objects
    Register my_register;
    Memory my_memory;
    CU controlunit(my_memory, my_register);

    //doing the test
    my_register.setCell(registeraddress, valuebefore);
    controlunit.Load_register_with_value(registeraddress, valueafter);

    //checking and logging
    string testname = "test_cu_load_with_value_" + to_string(registeraddress) + "_" + valuebefore + "_" + valueafter;
    if(my_register.getCell(registeraddress) == valueafter)
        log_test(true, testname);
    else
        log_test(false, testname);

}

void Test::test_store(int registeraddress, std::string register_value, int memoryaddress, std::string memory_value) {
    //constructing needed objects
    Register my_register;
    Memory my_memory;
    CU controlunit(my_memory, my_register);

    //doing the test
    my_register.setCell(registeraddress, register_value);
    my_memory.setCell(memoryaddress, memory_value);
    controlunit.store_content_of_R_in_memory_address_X(registeraddress, memoryaddress);

    //checking and logging test
    string testname = "test_store_" + to_string(registeraddress) + '_' + register_value + '_' + to_string(memoryaddress) + '_' + memory_value;
    if(my_memory.getCell(memoryaddress) == my_register.getCell(registeraddress))
        log_test(true, testname);
    else
        log_test(false, testname);
}

void Test::test_move(int R, int S) {
    //constructing needed objects
    Register my_register;
    Memory my_memory;
    CU controlunit(my_memory, my_register);

    //doing test
    my_register.setCell(R, "33");
    my_register.setCell(S, "23");
    controlunit.move_from_register_R_to_S(R, S);

    //checking and logging test
    string test_name = "test_move";
    if(my_register.getCell(S) == "33")
        log_test(true, test_name);
    else
        log_test(true, test_name);

}


void Test::test_bitwise_OR(int S, int T, string S_content, string T_content, string expected) {
    //constructing needed objects
    Register my_register;
    Memory my_memory;
    ALU alu(my_memory, my_register);

    //doing test
    my_register.setCell(S,  S_content);
    my_register.setCell(T, T_content);
    int R = 8;
    alu.BitWise_OR(8, S, T);

    //checking
    string testname = "test_ALU_S:" + to_string(S) + '_' + S_content + "_T:_" + to_string(T) + '_' + T_content;
    if(my_register.getCell(R) == expected)
        log_test(true, testname);
    else
        log_test(false, testname);
}


void Test::test_shift(string R_content, int shift_key, string expected) {
    //constructing needed objects
    Register my_register;
    Memory my_memory;
    ALU alu(my_memory, my_register);

    //doing test
    int R = 3;
    my_register.setCell(3, R_content);
    alu.shift_the_content(3, shift_key);

    //check
    string testname = "test_shift_R:_" + R_content + "_shift_key:_" + to_string(shift_key) + "_expected:_" + expected;
    if(my_register.getCell(3) == expected)
        log_test(true, testname);
    else
        log_test(false, testname);

}

void Test::test_twos_complement(string S_content, string T_content, string expected) {
    //constructing needed objects
    Register my_register;
    Memory my_memory;
    ALU alu(my_memory, my_register);

    //doing the test
    my_register.setCell(6, S_content);
    my_register.setCell(7, T_content);
    alu.add_twos_complement(8, 6, 7);

    //checking
    string testname = "test_two_complement_S_content:_" + S_content + "_T_content:_" + T_content + "_expected:_" + expected;
    if(my_register.getCell(8) == expected)
        log_test(true, testname);
    else
        log_test(false, testname);

}

void Test::test_bitwise_XOR(string S_content, string T_content, string expected) {

    //constructing needed objects
    Register my_register;
    Memory my_memory;
    ALU alu(my_memory, my_register);

    //doing the test
    my_register.setCell(6, S_content);
    my_register.setCell(7, T_content);
    alu.bitwiseXOR(8, 6, 7);

    //checking
    string testname = "test_bitwiseXOR_S_content:_" + S_content + "_T_content:_" + T_content + "_expected:_" + expected;
    if(my_register.getCell(8) == expected)
        log_test(true, testname);
    else
        log_test(false, testname);

}
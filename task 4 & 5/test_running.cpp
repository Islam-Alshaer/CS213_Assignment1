#include "Test.h"

using namespace std;

int main(){

    Test test("testing_log_file.txt");
    //testing set_cell and get_cell all at once
    test.test_memory_set_cell(0, "AA");
    test.test_memory_set_cell(15, "fn");
    test.test_memory_set_cell(550, "00");
    //testing clear memory
    test.test_clear_memory(5, "FF");
    test.test_clear_memory(0, "45");




}
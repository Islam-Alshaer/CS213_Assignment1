#include "Machine.h"
#include "fstream"

//prototypes
void print_from_0_to_F(char hex_numbers[]);

Machine::Machine() : memory(), processor(memory){

}

void Machine::load_file_into_memory(ifstream program_file) {
    const int max_instructions = 255 / 2;
    int number_of_instructions{0};
    string instruction;

    while(cin >> instruction){
        store_instruction(instruction);
        number_of_instructions++;
        if(number_of_instructions >= max_instructions)
            break;
    }
}

void Machine::store_instruction(string &insturction){
    static int current_cell = 0;
    for (int i = 0; i < insturction.length(); i += 2) {
        string one_byte; //one byte is two hexadicimal digits
        if(i == insturction.length() - 1)
            one_byte += insturction[i];
        else
            one_byte += insturction[i] + insturction[i + 1];

        memory.setCell(current_cell, one_byte);
        current_cell++;
    }

}

void Machine::complete_execution() {
    try{
        while(true){
            run_single_step();
        }
    }
    catch (exception &e){
        return;
    }
}


void Machine::run_single_step() {
    try{
        processor.run_next_instruction(memory);
    }
    catch (const exception& e){
        cout << e.what() << endl;
        throw;
    }
}


void Machine::display_state() {
    print_register();
    print_memory();
}

void Machine::print_register() const{
    Register machine_register;
    machine_register = processor.get_register();
    cout << "register :\n";
    for (int i = 0; i < 16; ++i) {
        cout << "R" << i << ": " << machine_register.getCell(i) << " ";
        //print a new line every 2 elements
        if(i % 2 == 0)
            cout << '\n';
    }
    cout << endl;
}

void Machine::print_memory() const{
    cout << "memory:\n";
    char hex_numbers[] = {'0', '1' ,'2' ,'3', '4', '5', '6', '7', '8', '9',
                          'A', 'B', 'C', 'D', 'E', 'F'};
    print_from_0_to_F(hex_numbers); //for showing the column number
    int column_pointer{0};
    for (int i = 0; i < 256; ++i) {
        cout << memory.getCell(i) << " ";
        // it's a 16 by 16 matrix
        if(i % 16 == 0) {
            cout << endl;
            cout << hex_numbers[column_pointer] << ' ';
            column_pointer++;
        }
    }
    cout << endl;
}

void print_from_0_to_F(char hex_numbers[]){
    for (int i = 0; i < 16; ++i) {
        cout << hex_numbers[i] << " ";
    }
}

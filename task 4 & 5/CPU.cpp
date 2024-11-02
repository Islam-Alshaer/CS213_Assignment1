#include "CPU.h"
#include "regex"
//prototypes
int get_memory_address(string IR);


CPU::CPU(Memory &machine_memory):
    cu(machine_memory, machine_register), alu(machine_memory, machine_register) {
}

void CPU::run_next_instruction(Memory memory) {
    if(not fetch(memory)){ //sorry for this bad code practice, this actually means fetch and check if it's done correctly
        throw runtime_error("instruction is not valid, could not fetch");
    }
    else{ //that means we have already fetched
        try{
            decode_and_excute();
        }
        catch (exception& e){
            throw runtime_error(e.what());
        }
    }
}

bool CPU::fetch(Memory &memory) {

    for(int i = 0; i < 2; i++) {
        IR += memory.getCell(pc);
        pc++; //run next step
    }
    if(not is_instruction_valid(IR) or pc > 255)
        return false;
    return true;
}

bool CPU::is_instruction_valid(string &instruction) {
    regex patten("^[1-6BC]{1}[0-9A-F]{3}$");
    if(regex_match(instruction, patten))
        return true;
    return false;
}


void CPU::decode_and_excute() { // I am truly ashamed to make one function this long : <

    char operation_code = IR[0];
    string hex_R;
    hex_R += IR[1];
    int R = stoi(hex_R, 0, 16);

    switch (operation_code) {

        case '1' : {
            int memory_address = get_memory_address(IR);
            cu.Load_register_with_value_in(R, memory_address);
        }
        case '2': {
            string value = IR.substr(2);
            cu.Load_register_with_value(R, value);
        }
        case '3': {
            string string_memory_address = IR.substr(2);
            int x = stoi(string_memory_address, 0, 16);
            cu.store_content_of_R_in_memory_address_X(R, x);
        }
        case '4': {
            if(IR[1] != '0')
                return;
            R = stoi(to_string(IR[2]), 0, 16); // very counterintuitive, but it's proffessor's fault :)
            int S = stoi(to_string(IR[3]), 0, 16);
            cu.move_from_register_R_to_S(R, S);
        }
        case '5': { //TODO : mr.y3zof

        }
        case '6': { //TODO : mr.y3zof

        }
        case 'B': {
            string string_memory_address = IR.substr(2);
            int x = stoi(string_memory_address, 0, 16);
            cu.jump_to_instruction_in_address(R, x, pc);
        }
        case 'C': { //halt
            if(IR[1] != '0' or IR[2] != '0' or IR[3] != '0')
                return;
            cu.halt(pc);
            throw runtime_error("halt execution");
        }

    }
    IR.clear();
}

int get_memory_address(string IR){
    string hexa_memory_address = IR.substr(2);
    int memory_address = stoi(hexa_memory_address, 0, 16);
    return memory_address;
}


Register CPU::get_register() const{
    return this->machine_register;
}
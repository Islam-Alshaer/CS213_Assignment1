#include "ALU.h"
#include "Register.h"
#include <map>
#include <cmath>
using namespace std;

ALU::ALU(Memory &machine_memory, Register &machine_register) :
    machine_memory(&machine_memory), machine_register(&machine_register){

}

map<char, string> hexAndDecMap = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"}
};


void ALU::add_twos_complement(int R, int S, int T){
    int content_of_S = stoi(machine_register->getCell(S), 0, 16);
}

void ALU::add_float_representation(int R, int S, int T) {

}



#include <iostream>
#include <string>
#include <stdexcept>

#include "io.cpp"
#include "simulator.cpp"

using namespace std;

unsigned int* const memory = new unsigned int[65536U];
int* const registers = new int[8U];

int main(int argc, char* argv[]) {
    if (argc < 2) {
        throw runtime_error("need a source file to be executed.");
    }

    string in_file_name = argv[1];
    
    // load 4-byte instruction into memory via buffer
    load_memory(memory, in_file_name);

    // simulate loaded instruction from memory
    simulate(memory, registers);

    delete[] memory;
    delete[] registers;
}

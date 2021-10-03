#include <iostream>
#include <string>
#include <stdexcept>

#include "io.cpp"
#include "parser.cpp"
#include "simulator.cpp"

using namespace std;

unsigned int* const memory = new unsigned int[65536U];
int* const registers = new int[8U];

int main(int argc, char* argv[]) {
    if (argc < 2) {
        throw runtime_error("need a source file to be executed.");
    }

    string in_file_name = argv[1];

    int file_size = get_file_size(in_file_name);

    // every instruction has 4-byte length, so it must follow size of n * 4
    if (file_size % 4) {
        throw runtime_error("unwell formatted binary instruction file.");
    }

    // get file binary buffer
    char* buffer = load_file_buffer(in_file_name, file_size);

    // load 4-byte instruction into memory via buffer
    parse_buffer(memory, buffer, file_size);

    delete[] buffer;

    // simulate loaded instruction from memory
    simulate(memory, registers);

    delete[] memory;
    delete[] registers;
}

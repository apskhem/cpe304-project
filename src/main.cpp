#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <string>
#include <stdexcept>

#include "io.cpp"
#include "parser.cpp"

using namespace std;

const unsigned int mem_size = 262144U; // 65536 words = 262144 bytes

int main(int argc, char *argv[]) {
    string in_file_name = argv[1];
    char* const memory = new char[mem_size];

    int file_size = get_file_size(in_file_name);
    load_file_buffer(in_file_name, memory, mem_size);

    // every instruction has 4-byte length, so it must follow size of n * 4
    if (file_size % 4) {
        throw runtime_error("Error: unwell formatted binary instruction file.");
    }

    cout << *(memory + 0) << " " << file_size <<  endl;
}
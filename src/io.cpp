#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

int get_file_size(string path) {
    ifstream in_file(path, ios::binary);

    if (!in_file) {
        throw runtime_error("Error: could not open file " + path + ".");
    }

    in_file.seekg(0, ios::end);
    int fsize = in_file.tellg();

    in_file.close();

    return fsize;
}

void load_file_buffer(string path, char* memory, int size) {
    ifstream in_file(path, ios::binary);

    if (!in_file) {
        throw runtime_error("Error: could not open file " + path + ".");
    }

    in_file.read(memory, size);

    in_file.close();
}
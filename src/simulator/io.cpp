#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

void parse_file_buffer(unsigned int* mem, string in) {
    // every instruction has 4-byte length, so it must follow size of n * 4
	if (in.size() % 4) {
		throw runtime_error("unwell formatted binary instruction input.");
	}

	int len = in.size();
	unsigned int instr = 0;
    int mem_idx = 0;
	int i = 0;

	while (true) {
		if (i % 32 == 0 && i != 0) {
            mem[mem_idx] = instr;
			mem_idx += 1;
		}
		
		instr = instr << 1;

		if (i >= len) {
			break;
		}

		if (in[i] == '1') {
			instr += 1;
		}

		i += 1;
	}
}

char* load_memory(unsigned int* mem, string path) {
    ifstream in_file(path, ios::binary);

    if (!in_file) {
        throw runtime_error("could not open file " + path + ".");
    }

    string text;
    getline(in_file, text);
    parse_file_buffer(mem, text);
    in_file.close();
}
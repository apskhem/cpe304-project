#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cmath>
#include<stdio.h>

#include "machinecodeconvert.cpp"

using namespace std;

void write_binary(string in, string path) {
	if (in.size() % 4) {
		throw runtime_error("unwell formatted binary instruction input.");
	}

	ofstream out(path, fstream::out);

	int len = in.size();
	unsigned char byte = 0;
	int i = 0;
	while (true) {
		if (i % 8 == 0 && i != 0) {
			out << byte;
			byte = 0;
		}
		else {
			byte = byte << 1;
		}

		if (i >= len) {
			break;
		}

		if (in[i] == '1') {
			byte += 1;
		}

		i++;
	}

	out.close();
}

// 48 to 57 char(0 to 9)
int main(int argc, char* argv[]) {
	// check for input file argument
	if (argc < 2) {
        throw runtime_error("need a source file to be executed.");
    }

    string in_file_name = argv[1];

	// transform string
	string* machineCode = to_machine_code(in_file_name);

	// join all string lines together
	string full_str = "";

	for (int i = 0; i < lines; i++) {
		full_str += machineCode[i];
		// cout << machineCode[i].length() << endl;
	}

	cout << full_str << endl;
	cout << full_str.size() << endl;

	// write file in binary
	write_binary(full_str, "tests/machine/out.bin");
	

	delete[] machineCode;
}

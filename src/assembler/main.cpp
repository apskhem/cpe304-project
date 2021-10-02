#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cmath>
#include<stdio.h>

#include "machinecodeconvert.cpp"

using namespace std;

// 48 to 57 char(0 to 9)

void write_binary(string in, string file) {
	cout << in.size() << endl;

	ofstream myfile;
	myfile.open("example.bin", std::fstream::out);
	myfile << (unsigned char) 255 << (unsigned char) 255;
	myfile.close();
}


int main(int argc, char* argv[]) {
	if (argc < 2) {
        throw runtime_error("Error: need a source file to be executed.");
    }

    string in_file_name = argv[1];

	string* machineCode = to_machine_code(in_file_name);

	string full_str = "";

	for (int i = 0; i < lines; i++) {
		full_str += machineCode[i];
		// cout << machineCode[i].length() << endl;
	}

	cout << full_str << endl;

	write_binary(full_str, "out.bin");
}



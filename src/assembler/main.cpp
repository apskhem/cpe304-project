#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cmath>
#include<stdio.h>


#include "machinecodeconvert.cpp"

using namespace std;

// 48 to 57 char(0 to 9)


int main(int argc, char* argv[]) {
	if (argc < 2) {
        throw runtime_error("Error: need a source file to be executed.");
    }

    string in_file_name = argv[1];

	string* machineCode = to_machine_code(in_file_name);

	for (int i = 0; i < lines; i++) {
		cout << machineCode[i] << endl;
	}
}



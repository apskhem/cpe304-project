#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cmath>
#include<stdio.h>

#include "machinecodeconvert.cpp"

using namespace std;

void create_file(string data, string path){
	ofstream myfile;
  	myfile.open (path, fstream::out);
  	myfile << data;
  	myfile.close();
}

// 48 to 57 char(0 to 9)
int main(int argc, char* argv[]) {
	// check for input file argument
	if (argc < 2) {
		throw runtime_error("need a source file to be executed.");
	}

	string infile = argv[1];

	// transform string
	string bin_str = to_machine_code(infile);

	// cout << bin_str << endl;

	// write file in binary
	if (argc < 4) {
		create_file(bin_str, "tests/machine/out.txt");
	}
	else {
		string outfile = argv[3];
		create_file(bin_str, outfile);
	}
}

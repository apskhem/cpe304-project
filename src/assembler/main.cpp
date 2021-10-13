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
	if (argc < 2) throw runtime_error("need a source file to be executed.");
	
	string infile = argv[1];

	int beginIdx = infile.rfind('/');
	string filename = infile.substr(beginIdx + 1);
	int dotIdx = filename.find('.');
	string name = filename.substr(0, dotIdx);

	// transform string
	string bin_str = to_machine_code(infile);

	// write file in binary
	create_file(bin_str, "tests/machine/" + name + ".out.txt");
	cout<<"exit(0)";
	
	return 0;
	
}

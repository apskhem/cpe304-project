#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cmath>
#include<stdio.h>

#include "machinecodeconvert.cpp"

using namespace std;

void create_file(string machineCode, string path){
	ofstream myfile;
  	myfile.open (path + ("_out.txt"), fstream::out);
  	myfile << machineCode;
  	myfile.close();
}

// 48 to 57 char(0 to 9)
int main(int argc, char* argv[]) {
	// check for input file argument
//	if (argc < 2) {
  //      throw runtime_error("need a source file to be executed.");
  //  }

  //  string in_file_name = argv[1];

	string in_file_name = "combination";
	
	string fileName = in_file_name + ".txt";

	// transform string
	string* machineCode = to_machine_code(fileName);

	// join all string lines together
	string full_str = "";

	for (int i = 0; i < lines; i++) {
		full_str += machineCode[i];
		//cout << machineCode[i].length() << endl;
	}

	//cout << full_str << endl;
	cout << full_str.size() << endl;

	// write file in binary
	//	write_binary(full_str, "combination");
	create_file(full_str, in_file_name);
	
	delete[] machineCode;
}

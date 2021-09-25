#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cmath>
#include<stdio.h>

#include "machinecodeconvert.cpp"

using namespace std;

int main(){
	stringstream ss;
	string instLine;
	string arg0, arg1, arg2, arg3, arg4;
	
	int lines = 0;
	
	ifstream inputFile;
	inputFile.open("inputassemblytest.txt");
	
	while(getline(inputFile,instLine)){
		lines = lines+1;
	}
	inputFile.close();
	
	string mc[lines], mem[lines];
	
	inputFile.open("inputassemblytest.txt");
	
	int j = 0;
	
	while(getline(inputFile,instLine)){
		ss<<instLine;
		ss>>arg0>>arg1>>arg2>>arg3;
		//cout<<arg0<<endl<<arg1<<endl;
		if(arg0 == "and");
		else if (arg0 == "nand");
		else if (arg0 == "lw");
		else if (arg0 == "sw");
		else if (arg0 == "beq");
		else if (arg0 == "jalr");
		else if (arg0 == "done");
		else if (arg0 == "noop");
		else mem[j] = arg0;
		
		j++;
	} 
	inputFile.close();
	
	for(int i = 0;i < lines;i++){
		cout<<mem[i]<<endl;
	}
	

	return 0;
}

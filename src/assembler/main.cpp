#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cmath>
#include<stdio.h>


#include "machinecodeconvert.cpp"

using namespace std;

// 48 to 57 char(0 to 9)

int main(){
	stringstream ss;
	string instLine;
	string arg[6];
	
	int lines = 0;
	
	ifstream inputFile;
	inputFile.open("inputassemblytest.txt");
	
	while(getline(inputFile,instLine)) lines = lines+1;
	
	inputFile.close();
	
	string mc[lines] = {}, 
		   mem[lines] = {};
		   
	for(int i = 0; i < lines;i++) mem[i] = "NT";
	
		   
	char instType[lines];
	
	inputFile.open("inputassemblytest.txt");
	
	int j = 0;
	
	while(getline(inputFile,instLine)){
		stringstream inputSs;
		inputSs<<instLine;
		inputSs>>arg[0];
		
		instType[j] = type(arg[0]);
		if(instType[j] == '0' || instType[j] == 's') mem[j] = arg[0];
		j++;
	} 
	inputFile.close();
	
	j = 0;
	
	inputFile.open("inputassemblytest.txt");
	while(getline(inputFile,instLine)){
		stringstream input;
		input<<instLine;
		
		if(instType[j] == 's'){
			input>>arg[4]>>arg[0]>>arg[1]>>arg[2]>>arg[3];
			instType[j] = type(arg[0]);
		}
		else input>>arg[0]>>arg[1]>>arg[2]>>arg[3];
		
		switch(instType[j]){
			case 'r':   
						for(int k = 1; k < 4;k++){
							if(!isNum(arg[k])) {
								for(int i = 0; i < lines; i++){
									if(arg[k] == mem[i]){
									stringstream num;
									num<<i;
									num>>arg[k];
									}		
								}
							}
						}
						mc[j] = rType(arg[0], arg[1], arg[2], arg[3]);
						break;
		
			case 'i':	
						for(int k = 1; k < 4;k++){
							if(!isNum(arg[k])) {
								for(int i = 0; i < lines; i++){
									if(arg[k] == mem[i]){
									stringstream num;
									num<<i;
									num>>arg[k];
									}		
								}
							}
						}
						mc[j] = iType(arg[0], arg[1], arg[2], arg[3]);
						break;
						
			case 'j': 	
						for(int k = 1; k < 3;k++){
							if(!isNum(arg[k])) {
								for(int i = 0; i < lines; i++){
									if(arg[k] == mem[i]){
									stringstream num;
									num<<i;
									num>>arg[k];
									}		
								}
							}
						}
						mc[j] = jType(arg[0], arg[1], arg[2]);
						break;				
			case 'o':
						if(arg[1] == "halt") mc[j] = oType(arg[1]);
						else mc[j] = oType(arg[0]);
						break;
							
			case '0':	
						if(!isNum(arg[2])) {
								for(int i = 0; i < lines; i++){
									if(arg[2] == mem[i]){
									stringstream num;
									num<<i;
									num>>arg[2];
									}		
								}
						}
						mc[j] = bitControlImm(decToBin(arg[2]));
						break;															
		}
		j++;
	}
	
	for(int i = 0; i < lines; i++){
		cout<<binToDec(mc[i])<<endl;
	}
	
	return 0;
}

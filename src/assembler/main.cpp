#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cmath>
#include<stdio.h>


#include "machinecodeconvert.cpp"

using namespace std;

// 48 to 57 char(0 to 9)

int main(char* fileName){
	
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
	
	while(getline(inputFile, instLine)){
		stringstream inputSs;
		inputSs<<instLine;
		inputSs>>arg[0]>>arg[1];
		
		instType[j] = type(arg[0], arg[1]);
		
		if(arg[1] == ".fill") mem[j] = arg[0];
		
		if(instType[j] == 'a') {
			stringstream temp;
			temp<<j;
			temp>>mem[j];
			mem[j] = arg[0] + ' ' + mem[j];
		}
		
		j++;
	} 
	inputFile.close();
	
	j = 0;
	
	inputFile.open("inputassemblytest.txt");
	while(getline(inputFile,instLine)){
		stringstream input;
		input<<instLine;
		
		if(instType[j] == 'a'){
			input>>arg[4]>>arg[0]>>arg[1]>>arg[2]>>arg[3];
			instType[j] = type(arg[0], arg[1]);
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
										break;
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
										break;
									}
									stringstream addr;
									string pos = "", name = "";
									addr<<mem[i];
									addr>>name>>pos;
									if(arg[k] == name){
										arg[k] = 'a' + pos;
									//	cout<<arg[k]<<endl<<pos<<endl<<k<<endl;
										break;
									}		
								}
							}
						}
						
						mc[j] = iType(arg[0], arg[1], arg[2], arg[3], j);
						break;
						
			case 'j': 	
						for(int k = 1; k < 3;k++){
							if(!isNum(arg[k])) {
								for(int i = 0; i < lines; i++){
									if(arg[k] == mem[i]){
										stringstream num;
										num<<i;
										num>>arg[k];
										break;
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
							
			case 'f':	
						if(!isNum(arg[2])) {
								for(int i = 0; i < lines; i++){
									if(arg[2] == mem[i]){
										stringstream num;
										num<<i;
										num>>arg[2];
										break;
									}
									stringstream addr;
									string pos = "", name = "";
									addr<<mem[i];
									addr>>name>>pos;
									if(arg[2] == name){
										arg[2] = pos;
										break;
									}		
									
								}
						}
						mc[j] = bitControlImm(decToBin(arg[2]));
						break;														
		}
		j++;
	}
	
	for(int i = 0; i < lines; i++){
		cout<<mc[i]<<endl;
	}
	
	return 0;
}

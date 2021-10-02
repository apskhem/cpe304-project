#include "bitconvert.cpp"
#include<fstream>

using namespace std;

string * output;

string bitControlReg(string inputBit){
	string control = "000";
	int i = control.length()-1;
	int j = inputBit.length()-1;
	while(j >= 0){
		control[i] = inputBit[j];
		i--;
		j--;
	}
	return control;
}

string bitControlImm(string inputBit){
	string control = "0000000000000000";
	if(inputBit[0] == '1')
	control = "1111111111111111";
	int i = control.length()-1;
	int j = inputBit.length()-1;
	while(j >= 0){
		control[i] = inputBit[j];
		i--;
		j--;
	}
	return control;
}

string rType(string inst, string regA = "000", string regB = "000", string destReg = "000" ){
	string addOpcode = "000", nandOpcode = "001", unuseBit = "0000000000000";
	string mc = "00000000";
	if(inst == "add"){
		mc = mc+addOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+unuseBit+bitControlReg(decToBin(destReg));
	}
	else{
		mc = mc+nandOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+unuseBit+bitControlReg(decToBin(destReg));
	}
	
	return mc;
}

string iType(string inst, string regA = "000", string regB = "000", string offset="0000000000000000" , int line = 0){
	string mc = "00000000", lwOpcode = "010", swOpcode = "011", beqOpcode = "100";
	
	if(inst == "lw") mc = mc+lwOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+bitControlImm(decToBin(offset));
	
	else if(inst == "sw") mc = mc+swOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+bitControlImm(decToBin(offset));

	else if(inst == "beq") {
			if(!isNum(offset)){
				stringstream offnum;
				int des;
				offnum<<offset.substr(1, offset.length() - 1);
				offnum>>des;
				des = des - 1 - line;				
				offset = to_string(des);
				
			}
			mc = mc + beqOpcode + bitControlReg(decToBin(regA)) + bitControlReg(decToBin(regB)) + bitControlImm(decToBin(offset));	
	}
	
	return mc;
}

string jType(string inst, string regA = "000", string regB = "000"){
	string mc = "00000000", jalrOpcode = "101", unuseBit = "0000000000000000";
	mc = mc+jalrOpcode + bitControlReg(decToBin(regA)) + bitControlReg(decToBin(regB)) + unuseBit;
	
	return mc;
}

string oType(string inst){	 
	string mc = "00000000", haltOpcode = "110", noopOpcode = "111", unuseBit = "0000000000000000000000";
	
	if(inst == "halt") mc = mc + haltOpcode + unuseBit;
	else mc = mc + noopOpcode + unuseBit;
	
	return mc;
}

char type(string inst, string label){
	if(inst == "add") return 'r';
	else if (inst == "nand") return 'r';
	else if (inst == "lw") return 'i';
	else if (inst == "sw") return 'i';
	else if (inst == "beq") return 'i';
	else if (inst == "jalr") return 'j';
	else if (inst == "done") return 'o';
	else if (inst == "noop") return 'o';
	else if (label == ".fill") return 'f';
	
	else return 'a';
}

string *to_machine_code(string fileName){
	stringstream ss;
	string instLine;
	string arg[6];
	
	int lines = 0;
	
	ifstream inputFile;
	inputFile.open(fileName);
	
	while(getline(inputFile,instLine)) lines = lines+1;
	
	inputFile.close();
	
	string* mc = new string[lines];
	string* mem = new string[lines];

	output = new string[lines];

	for(int i = 0; i < lines;i++) mem[i] = "NT";
	
	char instType[lines];
	
	inputFile.open(fileName);
	
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
	
	inputFile.open(fileName);
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
		output[i] = mc[i];
	}

	delete[] mc;
	delete[] mem;
	
	return output;
}




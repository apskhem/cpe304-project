#include "bitconvert.cpp"

using namespace std;

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




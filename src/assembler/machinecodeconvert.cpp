#include "bitconvert.cpp"

using namespace std;

string bitControlReg(string inputBit){
	string control = "000";
	int i = control.length()-1;
	int j = inputBit.length()-1;
	while(j >= 0){
		control[i]=inputBit[j];
		i--;
		j--;
	}
	return control;
}

string bitControlImm(string inputBit){
	string control = "0000000000000000";
	int i = control.length()-1;
	int j = inputBit.length()-1;
	while(j>=0){
		control[i]=inputBit[j];
		i--;
		j--;
	}
	return control;
}

string rType(string inst, string regA = "000", string regB = "000", string destReg = "000" ){
	string addOpcode = "000", nandOpcode = "001", unuseBit = "0000000000000";
	string mc = "";
	if(inst == "add"){
		mc = addOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+unuseBit+bitControlReg(decToBin(destReg));
	}
	else{
		mc = nandOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+unuseBit+bitControlReg(decToBin(destReg));
	}
	
	return mc;
}

string iType(string inst, string regA="000", string regB="000", string offset="0000000000000000" ){
	string mc = "", lwOpcode = "010", swOpcode = "011", beqOpcode = "100";
	if(inst == "lw"){
		mc = lwOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+bitControlImm(decToBin(offset));//use othor funtion
	}
	else if(inst=="sw"){
		mc = swOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+bitControlImm(decToBin(offset));
	}
	else{
		mc = beqOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+bitControlImm(decToBin(offset));
	}
	
	return mc;
}

string jType(string inst, string regA = "000", string regB = "000"){
	string mc = "", jalrOpcode = "101", unuseBit = "0000000000000000";
	mc = jalrOpcode + bitControlReg(decToBin(regA)) + bitControlReg(decToBin(regB)) + unuseBit;
	
	return mc;
}

string oType(string inst){	 
	string mc = "", haltOpcode = "110", noopOpcode = "111", unuseBit = "0000000000000000000000";
	
	if(inst == "halt") mc = haltOpcode + unuseBit;
	else mc = noopOpcode + unuseBit;
	
	return mc;
}

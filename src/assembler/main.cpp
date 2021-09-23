#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cmath>
#include<stdio.h>

using namespace std ;

string decToBin(string decimal){
	stringstream ss;
	int decimalInput=0;
	ss<<decimal;
	ss>>decimalInput;
	string bin ="";
	for(int i=decimalInput; i>0; i=i/2){
		if(i%2==1){
			bin = "1"+bin;
		}
		else{
			bin = "0"+bin;
		}
	}
	return bin;
}

string binToDec(string binary){
	int decimal = 0;
	int j = 0;
	int digit;
	string decimalStr = "";
	stringstream ss;
	
	for(int i=binary.length()-1;i>=0;i--){
		
		if(binary[i]=='1'){
			decimal += pow(2,j);
		}
		
		j++;
	}
	ss<<decimal;
	ss>>decimalStr;
	return decimalStr;
}

string bitControlReg(string inputBit){
	string control = "000";
	int i = control.length()-1;
	int j = inputBit.length()-1;
	while(j>=0){
		control[i]=inputBit[j];
		i--;
		j--;
	}
	return control;
}

string rType(string inst, string regA="000", string regB="000", string destReg="000" ){
	string addOpcode ="000", nandOpcode ="001", unuseBit ="0000000000000";
	string mc="";
	if(inst=="add"){
		mc = mc+addOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+unuseBit+bitControlReg(decToBin(destReg));
	}
	else{
		mc = mc+nandOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+unuseBit+bitControlReg(decToBin(destReg));
	}
	
	return mc;
}

string iType(string inst, string regA="000", string regB="000", string offset="0000000000000000" ){
	string mc="", lwOpcode ="010", swOpcode = "011", beqOpcode = "100";
	if(inst=="lw"){
		mc = mc+lwOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+bitControlReg(decToBin(offset));//use othor funtion
	}
	else if(inst=="sw"){
		mc = mc+swOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+bitControlReg(decToBin(offset));
	}
	else{
		mc = mc+beqOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+bitControlReg(decToBin(offset));
	}
	
	return mc;
}

string jType(string inst, string regA="000", string regB="000"){
	string mc="", jalrOpcode="101", unuseBit="0000000000000000";
	mc = mc+jalrOpcode+bitControlReg(decToBin(regA))+bitControlReg(decToBin(regB))+unuseBit;
	
	return inst;
}

string oType(string inst){
	string mc="", haltOpcode="110", noopOpcode="111", unuseBit="0000000000000000000000";
	if(inst=="halt"){
		mc = mc+haltOpcode+unuseBit;
	}
	else{
		mc = mc+noopOpcode+unuseBit;
	}
	
	return inst;
}





int main(){
	stringstream ss;
	string instLine="add 1 2 1";
	string arg0, arg1, arg2, arg3, arg4;
	int lines=0;
	ss<<instLine;
	ss>>arg1>>arg2>>arg3>>arg4;
	
	string s;
	s = rType(arg1, arg2, arg3, arg4);
	cout<<s<<endl;
	cout<<decToBin("655361")<<endl;
	cout<<binToDec(s);
	
	
	/*ifstream inputFile;
	inputFile.open("inputassembly.txt");
	
	while(getline(inputFile,instLine)){
		lines = lines+1;
	}
	inputFile.close();*/
	

	return 0;
}

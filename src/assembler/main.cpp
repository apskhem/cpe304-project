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

string bitControl(string inputBit){
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
		mc = mc+addOpcode+bitControl(decToBin(regA))+bitControl(decToBin(regB))+unuseBit+bitControl(decToBin(destReg));
	}
	else{
		mc = mc+nandOpcode+bitControl(decToBin(regA))+bitControl(decToBin(regB))+unuseBit+bitControl(decToBin(destReg));
	}
	
	return mc;
}

string iType(string inst, string regA="000", string regB="000", string offset="0000000000000000" ){
	return inst;
}

string jType(string inst, string regA="000", string regB="000"){
	string unuseBit="0000000000000000";
	return inst;
}

string oType(string inst){
	string unuseBit="0000000000000000000000";
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

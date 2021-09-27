#include<iostream>
#include<sstream>
#include<string>
#include<cmath>

using namespace std;

string decToBin(string decimal){
	stringstream ss;
	int decimalInput = 0;
	int count = 0;
	ss<<decimal;
	ss>>decimalInput;
	string bin = "";
	if(decimal[0] == '-') decimalInput = abs(decimalInput);
	for(int i = decimalInput; i > 0; i = i/2){
		if(i%2 == 1){
			bin = "1" + bin;
		}
		else{
			bin = "0" + bin;
		}
		count++;
	}
	if(decimal[0] == '-'){
		for(int i = 0; i < count;i++){
			if(bin[i] == '0') bin[i] = '1';
			else if (bin[i] == '1') bin[i] = '0';
		}
		for(int i = count-1; i >= 0;i--){
			if(bin[i] == '0') {
				bin[i] = '1';
				break;
			}
			else bin[i] = '0';
		}
		bin = "1" + bin;
	}
	else bin = "0" + bin;
		
	
	return bin;
}

string binToDec(string binary){
	int decimal = 0;
	int j = 0;
	int digit;
	bool isNeg = false;
	string decimalStr = "";
	stringstream ss;
	if(binary[0] == '1'){
		isNeg = true;
		for(int i = 0; i < binary.length();i++){
			if(binary[i] == '0') binary[i] = '1';
			else if (binary[i] == '1') binary[i] = '0';
		}
		for(int i = binary.length()-1; i >= 0;i--){
			if(binary[i] == '0') {
				binary[i] = '1';
				break;
			}
			else binary[i] = '0';
		}
	}
	
	for(int i = binary.length()-1;i >= 0;i--){
		if(binary[i] == '1')	decimal += pow(2,j);
		j++;
	}
	if(isNeg) decimal = decimal * (-1);
	
	ss<<decimal;
	ss>>decimalStr;
	return decimalStr;
}

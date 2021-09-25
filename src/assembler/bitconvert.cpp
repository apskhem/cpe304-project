#include<iostream>
#include<sstream>
#include<string>
#include<cmath>

using namespace std;

string decToBin(string decimal){
	stringstream ss;
	int decimalInput = 0;
	ss<<decimal;
	ss>>decimalInput;
	string bin = "";
	for(int i = decimalInput; i > 0; i = i/2){
		if(i%2 == 1){
			bin = "1" + bin;
		}
		else{
			bin = "0" + bin;
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
	
	for(int i = binary.length()-1;i >= 0;i--){
		
		if(binary[i]=='1')	decimal += pow(2,j);
		j++;
	}
	ss<<decimal;
	ss>>decimalStr;
	return decimalStr;
}

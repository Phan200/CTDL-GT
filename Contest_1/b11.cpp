#include <iostream>

using namespace std;

string Gray2Bi(string);
char xor_c(char a, char b){
	return (a==b)?'0':'1';
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string gray;
		cin>>gray;
		cout<<Gray2Bi(gray)<<endl;
	}
	return 0;
}

string Gray2Bi(string gray){
	string binary;
	binary+=gray[0];
	for(int i=1;i<gray.length();++i){
		binary+=xor_c(binary[i-1],gray[i]);
	}
	return binary;
}

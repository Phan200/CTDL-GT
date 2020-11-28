#include<iostream>

using namespace std;
char xor_c(char a, char b){
	return (a==b)? '0':'1';
}

string bi2Gray(string);

int main(){
	int t;
	cin>>t;
	while(t--){
		string binary;
		cin>>binary;
		cout<<bi2Gray(binary)<<endl;
	}
	return 0;
}

string bi2Gray(string binary){
	string gray;
	gray+=binary[0];
	for(int i=1;i<binary.length();i++){
		gray+=xor_c(binary[i-1],binary[i]);
	}
	return gray;
}

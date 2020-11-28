#include <iostream>
using namespace std;

string nextGen(string a){
	int i=a.length()-1;
	while(i>=0&&a[i]=='1'){
		a[i]='0';
		--i;
	}
	if(i>=0) a[i]='1';
	return a;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		cout<<nextGen(str)<<endl;
	}
	return 0;
}



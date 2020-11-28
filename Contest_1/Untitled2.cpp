#include <iostream>
#include <cstring>
using namespace std;

void nextGen(char a[]){
	int i=strlen(a)-1;
	while(a[i]=='1'){
		a[i]='0';
		--i;
	}
	a[i]='1';
}

int main(){
	int t;
	cin>>t;
	while(t--){
		char a[1000];
		cin>>a;
		nextGen(a);
		cout<<a<<endl;
	}
	return 0;
}



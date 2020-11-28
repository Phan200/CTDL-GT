#include <iostream>
using namespace std;

void init(int n,string str){
	for(int i=0;i<=n;++i){
		str[i]='A';
	}
}
void print(int n,string str){
	for(int i=0;i<=n;++i){
		cout<<str[i];
	}
}

int main(){
	int n;
	cin>>n;
	string str;
	init(n,str);
	print(n,str);
}

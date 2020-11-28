#include<iostream>

using namespace std;
int n;
char str[10];

void init();
bool check();
void nextString();
void print();

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		init();
		while(!check()){
			print();
			nextString();
		}
		print();
		cout<<endl;
    }
	return 0;
}

void init(){
	for(int i=1;i<=n;++i){
		str[i]='A';
	}
}
bool check(){
	for(int i=1;i<=n;++i){
		if(str[i]=='A') return false; 
	}
	return true;
}
void nextString(){
	int i=n;
	while(str[i]=='B'){
		str[i]='A';
		--i;
	}
	str[i]='B';
}

void print(){
	for(int i=1;i<=n;++i){
		cout<<str[i];
	}
	cout<<" ";
}


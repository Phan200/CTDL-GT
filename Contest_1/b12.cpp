#include <iostream>

using namespace std;
int n,k;
int flag=0;
char x[20];

void init();
bool check();
void nextGen();
void print();

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		flag=0;
		init();
		while(!check()){
			nextGen();
			if (flag==k){
			    print();
			}
		}
	}
	return 0;
}

void init(){
	for(int i=1;i<=n;++i){
		x[i]='0';
	}
}
bool check(){
	for(int i=1;i<=n;++i){
		if(x[i]=='0') return false;
	}
	return true;
}

void nextGen(){
	int i=n;
	while(i>0&&x[i]=='1'){
		x[i]='0';
		--i;
		--flag;
	}
	x[i]='1';
	++flag;
}
void print(){
	for(int i=1;i<=n;++i){
		cout<<x[i];
	}
	cout<<endl;
}

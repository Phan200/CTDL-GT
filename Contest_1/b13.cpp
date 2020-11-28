#include<iostream>

using namespace std;

int n,k;
bool ok=false;
int count=0;// so xau thoa man de bai
char x[20];
string s[1000000];//de luu xau thoa man in ra

void init(){
	for(int i=0;i<n;++i){
		x[i]='A';
	}
}


bool check(){
	int flag=1;// so lan xuat hien A
    int dup=0;// so lan day k so A xuat hien
	for(int i=0;i<n-1;++i){
		if(x[i]=='A'&&x[i+1]=='A'){
			++flag;
			if(flag>=k) ++dup;
		}
		else flag=1;
	}
	if(dup==1) return true;
	else return false;
}

void checkCount(){
	if(check()){
		s[count]="";
		for(int i=0;i<n;++i ){
			s[count]+=x[i];
		}
		++count;
		
	}
}

void nextGen(){
	int i=n-1;
	while(x[i]=='B'){
		x[i]='A';
		--i;
	}
	if(i<0) ok=true;
	else x[i]='B';
	
}



int main(){
	cin>>n>>k;
	init();
	while(!ok){
		nextGen();
		checkCount();
	}
	cout<<count<<endl;
	for(int i=0;i<count;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}


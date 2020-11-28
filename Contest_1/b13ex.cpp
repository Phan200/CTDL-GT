#include<iostream>
using namespace std;
bool ok=false;
int n,k,count=0; //count la bien dem ket qua.
char a[17];
string s[1000000]; //de chua cac day thoa man. 
void init(){
	for(int i=1;i<=n;i++)
			a[i]='A';
}
//ham kiem tra xem co dung yeu cau ko.
bool kt(){
	int d=0,t=1;
	for(int i=1;i<n;i++){
		if(a[i]=='A' && a[i+1]=='A'){
			t++;
			if(t>=k)	d++;
		}
		else{
			t=1;
		}
	}
	if(d==1)	return true;
	else	return false;
}
//Ham nay de dem so luong va them day duoc sinh vao string s.
void dem(){
	if(kt()){
		s[count]="";
		for(int i=1;i<=n;i++)
			s[count]+=a[i];
		count++;
	}
}

void sinh(){
	int i=n;
	while(a[i]=='B'){
		a[i]='A';
		i--;
	}
	if(i==0)	ok=true;
	else{
		a[i]='B';
	}
}
int main(){
	cin>>n>>k;
	init();
	while(!ok){
		sinh();
		dem();
	}
	cout<<count<<endl;
	for(int i=0;i<count;i++){
		cout<<s[i]<<endl;
	}
	
	return 0;
}

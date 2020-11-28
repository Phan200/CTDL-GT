#include <iostream>

using namespace std;
int n;
int x[10];

void init();
bool check();
void nextPermutation();
void print();

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		init();
		while(!check()){
			print();
			nextPermutation();
		}
		print();
		cout<<endl;
	}
	return 0;
}
void init(){
	for(int i=1;i<=n;++i){
		x[i]=i;
	}
}
bool check(){
	for(int i=1;i<=n;++i){
		if(x[i]!=n-i+1) return false;
	}
	return true;
}
void nextPermutation(){
	int i=n-1;
	while(i>0&&x[i]>x[i+1]) --i;
	if(i>0){
		int j=n;
		while(x[i]>x[j]) --j;
		int temp=x[i];
		x[i]=x[j];
		x[j]=temp;
		int k=i+1,s=n;
		while(k<s){
			temp=x[k];
			x[k]=x[s];
			x[s]=temp;
			++k;--s;
		}
	}
}
void print(){
	for(int i=1;i<=n;++i){
		cout<<x[i];
	}
	cout<<" ";
}

#include<iostream>

using namespace std;

int n;
int x[11];

void init();
bool check();
void next_Permutation();
void print();

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		init();
		while(!check()){
			print();
			next_Permutation();
		}
		print();
		cout<<endl;
	}
	return 0;
}

void init(){
	for(int i=1;i<=n;++i){
		x[i]=n-i+1;
	}
}
bool check(){
	for(int i=1;i<=n;++i){
		if(x[i]!=i) return false;
	}
	return true;
}
void next_Permutation(){
	int i=n-1;
	while(i>0&&x[i]<x[i+1]) --i;
	if(i>0){
		int j=n;
		while(x[i]<x[j]) --j;
		int temp=x[i];
		x[i]=x[j];
		x[j]=temp;
		int s=i+1,k=n;
		while(s<k){
			temp=x[s];
			x[s]=x[k];
			x[k]=temp;
			--k;++s;
		}
	}
}
void print(){
	for(int i=1;i<=n;++i){
		cout<<x[i];
	}
	cout<<" ";
}


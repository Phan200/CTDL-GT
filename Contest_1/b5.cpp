# include<iostream>

using namespace std;
int x[15];
int n,k;

void init();
bool check();
void nextCombination();
void print();

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>k;
		init();
		while(!check()){
			print();
			nextCombination();
		}
		print();
		cout<<endl;
	}
	return 0;
}

void init(){
	for(int i=1;i<=k;++i){
		x[i]=i;
	}
}
bool check(){
	for(int i=1;i<=k;++i){
		if(x[i]!=n-k+i) return false;
	}
	return true;
}
void nextCombination(){
	int i=k;
	// so sanh tu x[k]
	while(x[i]==n-k+i) --i;
	if(i>0){
		x[i]+=1;
		for(int j=i+1;j<=k;++j){
			x[j]=x[j-1]+1;
		}
	}
}
void print(){
	for(int i=1;i<=k;++i){
		cout<<x[i];
	}
	cout<<" ";
}

#include <iostream>

using namespace std;
int t,n,k;
int x[1000];
void nextCombination(){
	int i=k;
	while(i>0&&x[i]==n-k+i) i--;
	if(i!=0){
		x[i]=x[i]+1;
		for (int j=i+1;j<=k;++j) x[j]=x[i]+j-i;
	} 
	else {
		for(i=1;i<=k;++i) x[i]=i;
	}
	
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=k;++i){
			cin>>x[i];
		}
		nextCombination();
		for(int i=1;i<=k;++i){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

# include<iostream>

using namespace std;
int t,n;
int x[1000];

void print(){
	for(int i=1;i<=n;++i){
			cout<<x[i]<<" ";
	}
	cout<<endl;
}
void nextPermutation(){
	int i=n-1;
	while (i>0&&x[i]>x[i+1]) --i;
	if(i>0){
		int j=n;
		while(x[i]>x[j]) --j;
		int temp=x[i];
		x[i]=x[j];
		x[j]=temp;
		int s=n,k=i+1;
		while(k<s){
			temp=x[k];
			x[k]=x[s];
			x[s]=temp;
			--s;
			++k;
		}
	}
	else {
		for(int i=1;i<=n;++i){
			x[i]=i;
		}
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		nextPermutation();
		print();
	}
	return 0;
}

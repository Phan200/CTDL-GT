// Phan tich so

#include <iostream>

using namespace std;
int n,k,x[11]={0};

bool check(){
	for(int i=1;i<=k;++i){
		if(x[i]!=1) return false;
	}
	return true;
}

void print(){
	cout<<"(";
	for(int i=1;i<=k;++i){
		cout<<x[i];
		if(i!=k) cout<<" ";
	}
	cout<<") ";
}

void next_division(){
	int i=k,j,R,S,D;
	while(i>0&&x[i]==1)--i;
	if(i>0){
		x[i]-=1;
		D=k-i+1;
		R=D/x[i];
		S=D%x[i];
		k=i;
		if(R>0){
			for(j=i+1;j<=i+R;++j) x[j]=x[i];
			k+=R;
		}
		if(S>0){
			k+=1;
			x[k]=S;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		k=1;
		x[1]=n;
		int c=0;
		while(!check()){
			next_division();
			c++;
		}
		
		cout<<c+1<<endl;
	}
	return 0;
}

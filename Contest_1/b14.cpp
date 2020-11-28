#include <iostream>

using namespace std;

int n,k;
int mang_moi[50],mang_bd[50],mang_gnho[50];

int next_Combination();
int checkFlag(int);// so sanh so nguoi duoc nghi

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for (int i=1;i<=k;++i){
			cin>>mang_bd[i];
			mang_moi[i]=mang_bd[i];
		}
		cout<<next_Combination()<<endl;
	}
}

int next_Combination(){
	int i=k;
	while(i>0 && mang_moi[i]==n-k+i) --i;
	if(i>0){
		mang_moi[i]+=1;
		for(int j=i+1;j<=k;++j){
			mang_moi[j]=mang_moi[j-1]+1;
		}
		return checkFlag(i);
	}
	if (i==0) return k;
}
int checkFlag(int m){
	int flag=0;
	int p=1;
	int q=m;
	while(q<=k){
		if(mang_bd[q]<mang_moi[q]) ++flag; 
		if(mang_bd[q]>mang_moi[q]){
			mang_gnho[p]=mang_bd[q];
			++p;
			++flag;
		}
		++q;
	}
	for(int j=1;j<=p;++j){
		for(int s=m;s<=k;++s){
			if(mang_gnho[j]==mang_moi[s]) --flag;
		}
	}
	return flag;
}


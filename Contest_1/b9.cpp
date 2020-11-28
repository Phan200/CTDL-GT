#include<iostream>
#include<string>
#include<vector>

using namespace std;
int n;


void next_GrayCode();

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		next_GrayCode();
	}
	return 0;
}

void next_GrayCode(){
	vector<string> str;
	str.push_back("0");
	str.push_back("1");
	
	// vong lap dao nguoc lai 
	for(int i=2;i<(1<<n);i=i<<1){
		for(int j=i-1;j>=0;--j){
			str.push_back(str[j]);
		}
		// them "0" dang truoc nua mang dau
		for(int j=0;j<i;++j){
			str[j]="0"+str[j];
		}
		// them"1" dang truoc nua mang sau
		for(int j=i;j<2*i;j++){
			str[j]="1"+str[j];
		}
	}
	for(int i=0;i<str.size();++i){
		cout<<str[i]<<" ";
	}
	cout<<endl;
}


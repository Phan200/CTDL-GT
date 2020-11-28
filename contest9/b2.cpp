#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<int> ke[n];
    string s;
    for (int i=0;i<n;++i){
        string s;
        getline(cin,s);
        s+=" ";
        int j=0;
        int so=0;
        while(j<s.length()){
            //cout<<s[j]<<endl;
            if(s[j]>='0'&&s[j]<='9'){
                so=so*10+(s[j]-'0');
            } else if(so>0){
                
                ke[i].push_back(so);
                so=0;
            }
            j++;
        }
    }
    bool check[n+1];
    for(int i=0;i<n;++i) check[i+1]=true;
    for(int i=0;i<n;++i){
        check[i+1]=false;
        for(int j=0;j<ke[i].size();++j){
            if(check[ke[i][j]]) {
                cout<<i+1<<" "<<ke[i][j]<<endl;
            }
        }
    
    }
}
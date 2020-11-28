/*
Day vao queue
TAo funct mod(string,int) de tranh tran so
*/
#include<iostream>
#include<queue>
using namespace std;


void BinaryDigit(int n){
    queue<string> q;
    q.push("1");
    while(!q.empty()){
        string res=q.front(); q.pop();
        
        long long tmp=0;
        for(int i=0;i<res.length();++i){
            
            tmp=10*tmp+(res[i]-'0');
            tmp%=n;
            
        }
        if(tmp==0) {cout<<res<<endl; return;}
        q.push(res+"0");
        q.push(res+"1");

    }
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        BinaryDigit(n);
    }
}
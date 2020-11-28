#include<bits/stdc++.h>
using namespace std;
int n;
long long *rope;
void Init(){
    rope=new long long [n];
    for(int i=0;i<n;++i){
        cin>>rope[i];
    }
}
void Noi_Day(){
    priority_queue<long long,vector<long long>,greater<long long>> r;
    for(int i=0;i<n;++i){
        r.push(rope[i]);
    }
    long long c=0;//chi phi
    while(r.size()>1){
        long long f=r.top();
        r.pop();
        long long s=r.top();
        r.pop();
        c=c+f+s;
        r.push(f+s);
    }
    cout<<c<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        Init();Noi_Day();
    }
}
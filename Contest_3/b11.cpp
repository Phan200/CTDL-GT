#include<iostream>
#include<queue>

using namespace std;
const long long mod=1e9+7;
int n;
long long *rope;
void Noi_Day(){
    long long c=0;// chi phi
    priority_queue<long long,vector<long long>,greater<long long> > r(rope,rope+n);
    while(r.size()>1){
        long long f=r.top(); r.pop();
        long long s=r.top();r.pop();
        int temp=f+s;
        temp%=mod; 
        c=(c+temp)%mod;
        r.push(temp);
    }
    cout<<c<<endl;
}
int main(){
    cin>>n;
    rope=new long long [n];
    for(int i=0;i<n;++i){
        cin>>rope[i];
    }
    Noi_Day();
}
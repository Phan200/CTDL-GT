#include<iostream>
#define ll long long int
using namespace std;

const ll mod=1e9+7;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        ll res=1;
        cin>>n>>k;
        if(k>n) res=0;
        for(int i=n-k+1;i<=n;++i){
            res=(res*i)%mod;
        }
        cout<<res<<endl;
    }
    
}
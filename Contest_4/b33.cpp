#include<iostream>
#define ll long long int
using namespace std;

const ll mod=1e9+7;
ll power(ll x, ll k){
    if(k==1) return x%mod;
    ll res=power(x,k/2);
    if(k%2==0) return res*res%mod;
    return (res*res%mod)*x%mod;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll r=0, k=n;
        while(k>0){
            r=r*10+k%10;
            k/=10;
        }
        cout<<power(n,r)<<endl;
    }
    
}
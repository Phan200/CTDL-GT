#include<iostream>
#include<math.h>

#define ll unsigned long long int

using namespace std;
const ll mod=123456789;

ll Power(ll x){
    return x*x;
}
ll Try(ll n){
    if (n==0) return 1%mod;
    if(n==1) return 2%mod;
    ll p=Try(n/2);
    if(n%2==0) return (p%mod*p%mod)%mod;
    return 2*(Power(p)%mod)%mod;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;--n;
        cout<<Try(n)<<endl;
    }
    
}
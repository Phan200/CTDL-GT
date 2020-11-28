#include<iostream>
#define ll unsigned long long int

using namespace std;
const long long mod=1e9+7;

ll power(int x, ll k){
    ll ans =1;
    while(k>0){
        // neu k le, ans nhan them x
        if(k%2==1) ans=ans*x%mod;
        k/=2;
        x=x*x%mod; 
    }
    return ans;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        ll k;
        cin>>n>>k;
        cout<<power(n,k)<<endl;
    }
}
#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
ll *a;

void Solve(ll n){
    ll i=n/2+n%2-1;// vi tri o giua
    ll j=n-1;
    ll c=0;
    while(i>=0&&j>i){
        if(a[i]>=2*a[j]){
            --i;--j;
            ++c;
            
        } else --i;
    }
    cout<<n-c<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        a=new ll[n];
        int c=0;
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a,a+n,greater<ll>());
        Solve(n);
    }
    
}
#include<iostream>
#include<algorithm>

using namespace std;
#define ll long long int
int a[1000000];


int main(){
    
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        for(ll i=0;i<n;++i) cin>>a[i];
        sort(a,a+n);
        for(ll i=0;i<n;++i) cout<<a[i]<<" ";
        cout<<endl;
    }
    
}
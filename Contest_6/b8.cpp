#include<iostream>
#include<math.h>
#include<algorithm>

#define ll long long int
using namespace std;

ll count(ll x,ll y[],int m,ll a[]){
    if(x==0) return 0;
    if(x==1) return a[0];

    ll *idx=upper_bound(y,y+m,x);

    ll ans=(y+m)-idx;

    ans+=(a[0]+a[1]);
    if(x==2) ans-=(a[3]+a[4]);
    if(x==3) ans+=a[2];
    return ans;
}
ll CountPair(ll x[],ll y[],int n, int m){
    // luu cac lan dem cua 0,1,..4 trong y[]
    ll a[5]={0};
    for(int i=0;i<m;++i){
        if(y[i]<5) a[y[i]]++;
    }
    // sap xep de lam binary search
    sort(y,y+m);
    ll res=0;
    // lau tung phan tu trong x va dem cac cap hop le
    for(int i=0;i<n;++i){
        res+=count(x[i],y,m,a);
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        ll x[n],y[m];
        for(int i=0;i<n;++i) cin>>x[i];
        for(int i=0;i<m;++i) cin>>y[i];
        ll ans=CountPair(x,y,n,m);
        cout<<ans<<endl;
    }
    
}
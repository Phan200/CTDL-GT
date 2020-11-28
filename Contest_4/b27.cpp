// cac vi tri  le luon bang 1
// vi tri chan =0/1;

#include<iostream>
#include<vector>
#include<math.h>

#define ll long long int
using namespace std;

vector<ll> p;

void ChiaSo(ll n){
    int t=0;
    int s=2;
    while(n/2>=1){
        ++t;
        if(t==1){
            p.push_back(s);
        } else{
            s*=2;
            p.push_back(s);
        }
        n/=2;
    }
}
ll GiaTri_ith(ll k,ll n,ll pos){
    if(k%2==1) return 1;
    if(k==p[pos]) return n%2;
    else if(k<p[pos]) GiaTri_ith(k,n/2,pos-1);
    else if(k>p[pos]) GiaTri_ith(2*p[pos]-k,n/2,pos-1);
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll n,l,r;
        cin>>n>>l>>r;
        p.clear();
        ll res=0;
        ChiaSo(n);
        for(int i=l;i<=r;++i){
            res+=GiaTri_ith(i,n,p.size()-1);
        }
        cout<<res<<endl;
    }
    
}
#include<bits/stdc++.h>
#define ll long long int
using namespace std;


vector<int > b;
int main(){
    int t;cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll x=n;
        int s=0;
        while(x>0){
            int q=x%10; ++s;
            b.push_back(q);
            x/=10;
        }
        /*
        1003
        1001 ddooir lai tim so 
        20205
        1111
        */
        
        reverse(b.begin(),b.end());
        x=-1;
        for(int i=0;i<s;++i){
            if(b[i]>=2){
                x=i;
                break;
            }
        }
        if(x!=-1){
            for(int i=x;i<s;++i){
            b[i]=1;
        }
        }
        
        // for(int i=0;i<s;++i) cout<<b[i];
        // cout<<endl;
        ll res=0,k=1;
        for(int i=s-1;i>=0;--i){
            res+=b[i]*k;
            k*=2;
        }
         cout<<res<<endl;
    }
}
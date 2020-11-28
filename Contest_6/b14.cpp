#include<iostream>
#include<cstring>
#define ll long long int
using namespace std;

bool f[1000000];

void Init(){
    memset(f,true,sizeof(f));
    f[0]=f[1]=false;

    for(ll i=2;i<=1000000;++i){
        if(f[i]){
            for(ll j=i*i;j<=1000000;j+=i){
                f[j]=false;
            }
        }
    }
    
}
int main(){
    Init();
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        int ok=0;
        for(ll i=2;i<=n;++i){
            if(f[i]&&f[n-i]) {cout<<i<<" "<<n-i<<endl;ok=1;break;}
        }
        if(ok==0) cout<<-1<<endl;
    }
    
}
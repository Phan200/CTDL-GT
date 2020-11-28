#include<iostream>
#include<cstring>
#define ll long long int
using namespace std;


int main(){
    int t;
    cin>>t;
    ll f[100005];
    while (t--)
    {
        memset(f,0,sizeof(f));
        int n,m;
        cin>>n>>m;
        ll a[n],b[m];
        for(int i=0;i<n;++i){
            cin>>a[i];
            f[a[i]]++;
        }
        for(int i=0;i<m;++i){
            cin>>b[i];
            f[b[i]]++;
        }
        // in ra Union()
        ll s=max(a[n-1],b[m-1]);
        for(int i=1;i<=s;++i){
            if(f[i]>0) cout<<i<<" ";
        }
        cout<<endl;
        for(int i=1;i<s;++i){
            if(f[i]>1) cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
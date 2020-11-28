#include<iostream>
#include<algorithm>

using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        ll a[n],b[m];
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<m;++i) cin>>b[i];
        ll res;
        sort(a,a+m);
        res=a[m-1];
        sort(b,b+m);
        res*=b[0];
        cout<<res<<endl;

    }
    
}
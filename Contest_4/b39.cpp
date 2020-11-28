#include<iostream>
#define ll long long int
using namespace std;

// ll Search(ll a[],ll b[],ll l,ll r){
//     if(a[0]<b[0]) return 0;
//     if(a[r-1]==b[r-2]&&a[r]<b[r-1]) return r-1;
//     int k=(l+r)/2;
//     if(a[k]<b[k]&&a[k-1]==b[k-1]) return k;
//     else if(a[k]<b[k]) Search(a,b,l,k-1);
//     else if(a[k]==b[k]) Search(a,b,k+1,r); 
// }

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll a[n],b[n-1];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < n-1; i++)
        {
            cin>>b[i];
        }
        int i=0;
        while(i<n){
            if(a[i]!=b[i]){
                cout<<i+1<<endl;
                break;
            }
            ++i;
        }
    }
    
}
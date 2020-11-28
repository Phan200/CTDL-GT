#include<iostream>
#define ll long long int
using namespace std;

ll Floor_X(ll a[],ll x,ll f,ll l){
    if(x<a[f]) return -2;
    if(x>=a[l]) return l;
    ll mid=(f+l)/2;
    if(a[mid]<=x&&a[mid+1]>x) return mid;
    else if(a[mid]>x) Floor_X(a,x,f,mid-1);
    else if(a[mid]<x) Floor_X(a,x,mid+1,l);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        ll x;
        cin>>n>>x;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        cout<<Floor_X(a,x,0,n-1)+1<<endl;
    }
    
}
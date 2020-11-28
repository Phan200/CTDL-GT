#include<iostream>
#include<math.h>
#include<algorithm>

#define ll long long
using namespace std;
struct LL{
    ll val,i,ab;
};
bool comp(LL a,LL b){
    if(a.ab>b.ab) return false;
    if(a.ab==b.ab&&a.i>b.i) return false;
    return true;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,x;
        cin>>n>>x;
        LL a[n];
        for(int i=0;i<n;++i){
            cin>>a[i].val;
            a[i].ab=abs(x-a[i].val);
            a[i].i=i;
        }
        sort(a,a+n,comp);
        for (int i = 0; i < n; i++)
        {
            cout<<a[i].val<<" ";
        }
        cout<<endl;
    }
    return 0;
}
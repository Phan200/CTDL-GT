#include<iostream>
#include<algorithm>

using namespace std;
bool comp(int a,int b){
    return (a>b);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a,a+n,comp);
        for(int i=0;i<k;++i) cout<<a[i]<<" ";
        cout<<endl;
    }
    
}
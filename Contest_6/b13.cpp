#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k,dem=0;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;++i) {
            cin>>a[i];
            if(a[i]==k) ++dem;
        }
        if (dem==0) cout<<-1<<endl;
        else cout<<dem<<endl;
    }
    
}
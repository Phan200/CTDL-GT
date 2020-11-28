#include<iostream>
#include<algorithm>

using namespace std;
const unsigned int mod=1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long a[n];
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        sort(a,a+n);
        
        int res=0;
        for(int i=0;i<n;++i){
            res+=a[i]*i;
            res=res% mod;
        }
        cout<<res<<endl;
        
    }
}
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k,res=0;
        cin>>n>>k;
        int x[n];
        
        for(int i=0;i<n;++i) cin>>x[i];
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                if(x[i]+x[j]==k) ++res;
            }
        }
        cout<<res<<endl;
    }
    
}
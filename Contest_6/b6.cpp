#include<iostream>
#define ll long long int
using namespace std;
const ll mod=1e9+7;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        ll f[4]={0};
        int a;
        for(int i=0;i<n;++i){
            cin>>a;
            f[a]++;
        }
        for(int i=0;i<=2;++i){
            for(int j=1;j<=f[i];++j) cout<<i<<" ";
        }
        cout<<endl;
    }
    
}
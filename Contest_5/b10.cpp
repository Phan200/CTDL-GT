#include<iostream>
#define ll long long int
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        ll a[n][m];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j) cin>>a[i][j];
        }
        for(int i=1;i<n;++i){
            a[i][0]+=a[i-1][0];
        }
        for(int j=1;j<m;++j){
            a[0][j]+=a[0][j-1];
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                a[i][j]=min(a[i-1][j-1],min(a[i-1][j],a[i][j-1]))+a[i][j];
            }
        }
        cout<<a[n-1][m-1]<<endl;
    }
    
}
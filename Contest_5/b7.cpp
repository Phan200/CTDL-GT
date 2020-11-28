#include<iostream>
#include<cstring>
#define ll long long int
using namespace std;

const ll mod=1e9+7;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        ll dp[n+1];// dp[i] la so cach di bac i;
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;++i){
            for(int j=0;j<=min(i,k);++j){
                dp[i]+=dp[i-j];
                dp[i]%=mod;
            }
        }
        cout<<dp[n]<<endl;
    }
    
}
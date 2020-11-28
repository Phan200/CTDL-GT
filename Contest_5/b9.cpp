#include<iostream>
#include<cstring>
#define ll long long int
using namespace std;

const ll mod=1e9+7;
ll dp[101][50001];//dp[i][j] la so cac so co i chu so va tong la j

int main(){
    for(int i=1;i<=50000;++i){
        dp[0][i]=0;
    }
    for(int i=1;i<=100;++i){
        dp[i][0]=0;
    }
    for(int i=1;i<=9;++i){
        dp[1][i]=1;
    }
    
    for(int i=1;i<=100;++i){
        for(int j=0;j<=9;++j){
            for(int k=j;k<=50000;++k){
                dp[i][k]=(dp[i][k]%mod+dp[i-1][k-j]%mod)%mod;
            }
        }
    }
    
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        

        cout<<dp[n][k]<<endl;

    }
    
}


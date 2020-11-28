// Tinh nCk
// Su dung tam giac pascal
//Let us see how above formula works for C(4, 3)
// 1==========>> n = 0, C(0, 0) = 1
// 1–1========>> n = 1, C(1, 0) = 1, C(1, 1) = 1
// 1–2–1======>> n = 2, C(2, 0) = 1, C(2, 1) = 2, C(2, 2) = 1
// 1–3–3–1====>> n = 3, C(3, 0) = 1, C(3, 1) = 3, C(3, 2) = 3, C(3, 3)=1
// 1–4–6–4–1==>> n = 4, C(4, 0) = 1, C(4, 1) = 4, C(4, 2) = 6, C(4, 3)=4, C(4, 4)=1
// So here every loop on i, builds i’th row of pascal triangle, using (i-1)th row
#include<iostream>
#include<cstring>
#define ll long long int
using namespace std;
ll dp[1001][1001];
const ll mod=1e9+7;
int main(){
    
    for(int i=1;i<=1000;++i){
            for(int j=0;j<=i;++j){
                if(i==j||j==0) dp[i][j]=1;
                else dp[i][j]=(dp[i-1][j-1]%mod+dp[i-1][j]%mod)%mod;
            }
    }
    int t;
    cin>>t;
    
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        if(n*k!=0) cout<<dp[n][k]%mod<<endl;
        else cout<<1<<endl;
    }
    
}
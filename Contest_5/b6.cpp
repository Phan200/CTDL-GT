// O(n^2)

#include<iostream>
#include<cstring>
#define ll long long int
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        int res=1;
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        //co so quy hoach dong
        for(int i=0;i<n;++i) dp[i][i]=1;
        // khi tim thay 1 xau doi xung co do dai =2
        for (int i = 0; i < n; i++)
        {
            if(s[i]==s[i+1]){
                res=2;
                dp[i][i+1]=1;
            }
        }
        // khi do dai xau doi xung >2
        // k la chieu dai day doi xung co the cua string
        for(int k=3;k<=n;++k){
            for(int i=0;i<n-k+1;++i){
                int j=k+i-1;
                if(dp[i+1][j-1]==1&&s[i]==s[j]){
                    dp[i][j]=1;
                    res=max(res,k);
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
#include<iostream>

using namespace std;
int LRS(string s1,string s2,string s3,int a,int b,int c){
    int dp[a+1][b+1][c+1];
    for(int i=0;i<=a;++i){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;++k){
                if(i==0||j==0||k==0){
                    dp[i][j][k]=0;
                } else if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[k-1]){
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                } else {
                    dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                }
            }
            
        }
    }
    return dp[a][b][c];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        string s1,s2,s3;
        cin>>a>>b>>c>>s1>>s2>>s3;
        cout<<LRS(s1,s2,s3,a,b,c)<<"\n";
    }
}
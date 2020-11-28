#include<iostream>

using namespace std;

// int LargestSum(int a[],int n){
//     int dp[n+1];
//     a[0]=0;
//     dp[0]=0;
//     int res=-1;
//     for(int i=1;i<=n;++i){
//         if(a[i]>a[i-1]){
//             dp[i]=a[i]+dp[i-1];
//         } else{
//             int k=i-1;
//             while(a[k]>a[i]){
//                 k--;
//             }
//             dp[i]=dp[k]+a[i];
//         }
//         res=max(res,dp[i]);
//     }
//     return res;
// }

int BiggestSum(int a[],int n){
    int res=-1;
    int dp[n+1];
    for(int i=1;i<=n;++i){
        dp[i]=a[i];
    }
    dp[0]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            if(a[j]<a[i]&&dp[i]<dp[j]+a[i]){
                dp[i]=dp[j]+a[i];
            }
            res=max(res,dp[i]);
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        cout<<BiggestSum(a,n)<<"\n";
    }
    
}
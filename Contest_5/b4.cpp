// thay vi tim ra toi da so phan tu trong day
// thi tim toi thieu cac phan tu co tong dong du voi N theo mod l
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        int f[n+1][k+1];
        for(int i=1;i<=k;++i){
            f[0][i]=-10001;
        }
        f[0][0]=0;// rieng f[0][0]=0
        int a;
        
        for(int i=1;i<=n;++i){
            cin>>a;
            a%=k;
            for(int t=0;t<k;++t){
                f[i][t]=max(f[i-1][(t-a+k)%k]+1,f[i-1][t]);
            }
        }
        cout<<f[n][0]<<endl;
    }
    
}
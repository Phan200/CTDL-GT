#include<iostream>
#include<cstring>
using namespace std;
int f[1001][1001];

int main(){
        string s1,s2;
        cin>>s1>>s2;
        int m=s1.size();
        int n=s2.size();
        memset(f,0,sizeof(f));
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
            if(s1[i-1]==s2[j-1]){
                f[i][j]=f[i-1][j-1]+1;
            } else f[i][j]=max(f[i][j-1],f[i-1][j]);
        }
        }
        cout<<f[m][n]<<endl;
    
}

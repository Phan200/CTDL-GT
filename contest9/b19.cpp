#include<bits/stdc++.h>

using namespace std;
int G[1001][1001];
bool check[1001];
int v,e;

void DFS(int u,int n){
    check[u]=0;
    for(int i=1;i<=n;++i){
        if(check[i]&&G[u][i]==1){
            DFS(i,n);
        }
    }
}
int duyetLienThong(int n){
    int res=0;
    for(int i=1;i<=n;++i){
        if(check[i]){
            ++res;
            DFS(i,n);
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>v>>e;
        memset(G,0,sizeof(G));
        for(int i=0;i<e;++i){
            int dau,cuoi;
            cin>>dau>>cuoi;
            G[dau][cuoi]=G[cuoi][dau]=1;
        }
        memset(check,1,sizeof(check));
        int temp=duyetLienThong(v);
        for(int i=1;i<=v;++i){
            memset(check,1,sizeof(check));
            check[i]=false;
            int res=duyetLienThong(v);
            if(res>temp) cout<<i<<" ";
        }
        cout<<endl;
    }
    
}
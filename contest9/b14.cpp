#include<iostream>
#include<string>
#include<sstream>
#include<cstring> 
#include<queue>

using namespace std;
bool check[10001];
int G[10001][10001];
int n;

bool BFS(int u,int v){
    queue<int> qu;
    qu.push(u);
    check[u]=false;
    while(!qu.empty()){
        int top=qu.front();
        qu.pop();
        for(int i=1;i<=n;++i){
            if(check[i]&&G[top][i]==1){
                check[i]=false;
                if(i==v) return true;
                qu.push(i);
                
            }
            
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>n>>m;
        memset(G,0,sizeof(G));
        while(m--){
            int dau,cuoi;
            cin>>dau>>cuoi;
            G[dau][cuoi]=G[cuoi][dau]=1;
        }
        int q;
        cin>>q;
        
        while(q--){
            memset(check,1,sizeof(check));
            int dau, cuoi;
            cin>>dau>>cuoi;
            if(BFS(dau,cuoi)) cout<<"YES\n";
            else cout<<"NO\n";
        }
        
        
    }
}
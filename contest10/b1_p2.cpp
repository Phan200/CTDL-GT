
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

vector<int> edge[1001];
bool check[1001];
bool visit[1001];
int result[1001];

bool BFS(int v, int color,int k) 
{ 
    queue<int> q;
    q.push(k);
    visit[k]=false;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        vector<int> ::iterator it;
        memset(check,1,sizeof(check));
        for(it=edge[u].begin();it!=edge[u].end();++it){
            if(result[*it]!=0){
                check[result[*it]]=false; 
            }
            if(visit[*it]){
                visit[*it]=false;
                q.push(*it);
            }
        }
        for(int paint=1;paint<=color;++paint){
            // tim mau phu hop voi yeu cau
            if(check[paint]){
                result[u]=paint;
                break;
            } 
        }
        if(result[u]==0) return false;        
    }
    return true;
} 

bool ToMau(int v,int color){
    memset(result,0,sizeof(result));
    memset(visit,1,sizeof(visit));
    for(int i=1;i<=v;++i){
        if(visit[i]){
            if(BFS(v,color,i)) continue;
            else return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int v,e,color;
        cin>>v>>e>>color;
        for(int i=1;i<=v;++i) edge[i].clear();
         for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        ToMau(v,color) ? cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}
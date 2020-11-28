#include<bits/stdc++.h>

using namespace std;
vector<int> edge[1001];
bool check[1001];
set<int> visit;


bool BFS(int u,vector<int> root){
    queue<int> q;
    q.push(u);
    check[u]=false;
    while (!q.empty())
    {
        int t=q.front(); q.pop();
        vector<int> ::iterator i;
        for(i=edge[t].begin();i!=edge[t].end();++i){
            if(check[*i]){
                check[*i]=false;
                q.push(*i);
                root[*i]=t;
            } else if(*i!=root[t]) return true;
        }
    }
    return false;
}

bool isCycle(int v){
    memset(check,1,sizeof(check));
    vector<int> root(v+1,-1);
    for(int i=1;i<=v;++i){
        
        if(check[i]&&BFS(i,root)) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        visit.clear();
        int v,e;
        cin>>v>>e;
        for(int i=1;i<=v;++i) edge[i].clear();
        for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        
        
        if(isCycle(v)) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}
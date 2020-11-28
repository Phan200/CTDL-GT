#include<bits/stdc++.h>

using namespace std;
vector<int> edge[1001];
bool check[1001];
bool visit[1001];

bool DFS(int u){
    check[u]=false;
    visit[u]=false;
    vector<int>::iterator it;
    for(it=edge[u].begin();it!=edge[u].end();++it){
        if(check[*it]){
            if(DFS(*it)) return true;
        } else if(!visit[*it]) return true;
    }
    visit[u]=true;
    return false;
}

bool isCycle(int v){
    memset(check,1,sizeof(check));
    memset(visit,1,sizeof(visit));
    for(int i=1;i<=v;++i){
        if(DFS(i)) return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        for(int i=1;i<=v;++i) edge[i].clear();
        for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);
            
        }
        
        
        if(isCycle(v)) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}
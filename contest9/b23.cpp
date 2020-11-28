#include<bits/stdc++.h>

using namespace std;
vector<int> edge[1001];
bool check[1001];
set<int> visit;

bool DFS(int u,int parent){
    check[u]=false;
    vector<int>::iterator it;
    for(it=edge[u].begin();it!=edge[u].end();++it){
        if(check[*it]){
            if(DFS(*it,u)) return true;
        } else if(*it!=parent) return true;
    }
    return false;
}

bool isCycle(int v){
    memset(check,1,sizeof(check));
    for(int i=1;i<=v;++i){
        if(check[i]&&DFS(i,i)) return true;
    }
    return false;
}
int main(){
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
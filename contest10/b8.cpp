#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;
vector<int> node[10001];
bool check[10001];
vector<pair<int,int> > step;
int count;
void print(int n){
    if(count==n-1){
        for(int i=0;i<count;++i){
            cout<<step[i].first<<" "<<step[i].second<<"\n";
        }
    } else cout<<-1<<"\n";
}

void DFS(int u){
    check[u]=false;
    vector<int>::iterator it;
    for(it=node[u].begin();it!=node[u].end();++it){
        if(check[*it]){
            step.push_back(make_pair(u,*it));
            DFS(*it);
        }
    }
    
}
int main(){
    int t;cin>>t;
    while(t--){
        int v,e,u;
        cin>>v>>e>>u;
        for(int i=1;i<=v;++i) node[i].clear();
        for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            node[a].push_back(b);
            node[b].push_back(a);
        }
        memset(check,1,sizeof(check));
        step.clear();
        count=0;
        DFS(u);
        print(v);
        
    }
}
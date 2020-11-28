#include<bits/stdc++.h>

using namespace std;
vector<int> edge[1001];
bool check[1001];
int indg[1001];

bool BFS(int v){
    queue<int> q;
    for(int i=1;i<=v;++i){
        if(indg[i]==0) q.push(i);
    }
    int count=0;
    while(!q.empty()){
        int s=q.front(); q.pop();
        vector<int> ::iterator it;
        for(it=edge[s].begin();it!=edge[s].end();++it){
            if(--indg[*it]==0){
                q.push(*it);
            } 
        }
        ++count;
    }
    if(count!=v) return true;
    return false;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        memset(indg,0,sizeof(indg));
        for(int i=1;i<=v;++i) {
            edge[i].clear();
        }
        for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);
            indg[b]++;
        }
        
        if(BFS(v)) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}
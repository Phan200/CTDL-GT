#include<iostream>
#include<utility>
#include<vector>
#include<cstring>

using namespace std;
vector<int> edge[1001];
bool check[1001];
vector< pair<int,int> > temp;

void Reset(int v){
    for(int i=1;i<=v;++i){
        edge[i].clear();
    }
}
void DFS(int u,int n){
    check[u]=false;
    for(int i=0;i<edge[u].size();++i){
        if(check[edge[u][i]]){
            DFS(edge[u][i],n);
        }
    }
}
int SoLT(int n){
    int LT=0;
    memset(check,1,sizeof(check));
    for(int i=1;i<=n;++i){
        if(check[i]){
            ++LT;
            DFS(i,n);
        }
    }
    return LT;
}
void TimCanhCau(int k,int e,int v,vector<pair<int,int> > tmp,int lt){
    for(int i=0;i<e;++i){
        if(i!=k){
            edge[tmp[i].first].push_back(tmp[i].second);
            edge[tmp[i].second].push_back(tmp[i].first);
        }
    }
    int ans=SoLT(v);
    if(ans>lt){
        cout<<tmp[k].first<<" "<<tmp[k].second<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int v,e;
        cin>>v>>e;
        Reset(v);
        temp.clear();
        for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            temp.push_back({a,b});
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        
        int k=SoLT(v);
        for(int i=0;i<e;++i){
            Reset(v);
            TimCanhCau(i,e,v,temp,k);
        }
        cout<<endl;
    }
    
}
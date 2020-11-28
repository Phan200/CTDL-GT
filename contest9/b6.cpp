#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<algorithm>


using namespace std;
bool check[1001];
vector<int> ke[1001];

void DFS(int u){
    cout<<u<<" ";
    check[u]=false;
    for(int i=0;i<ke[u].size();++i){
        if(check[ke[u][i]]){
            DFS(ke[u][i]);
        }
    }
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin>>t;
    
    while (t--)
    {
    
    int v,e,i,j,u;
    cin>>v>>e>>u;
    for(i=1;i<=v;++i) ke[i].clear();
    for(i=0;i<e;++i){
        int node,end;
        cin>>node>>end;
        ke[node].push_back(end);
        ke[end].push_back(node);
    }
    memset(check,1,sizeof(check));
    DFS(u);
    cout<<endl;
    }
}
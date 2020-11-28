#include<bits/stdc++.h>

using namespace std;
vector<int> node[10001];
bool check[1001];
int v,e;

void BFS(int u,int n){
    queue<int> q;
    q.push(u);
    check[u]=false;
    while(!q.empty()){
        int s=q.front();
        q.pop();
        vector<int>::iterator it;
        for(it=node[s].begin();it!=node[s].end();++it){
            if(check[*it]){
                check[*it]=false;
                q.push(*it);
            }
        }
    }
}
int duyetLienThong(int n){
    int res=0;
    for(int i=1;i<=n;++i){
        if(check[i]){
            ++res;
            BFS(i,n);
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
        for(int i=1;i<=v;++i) node[i].clear();
        for(int i=0;i<e;++i){
            int dau,cuoi;
            cin>>dau>>cuoi;
            node[dau].push_back(cuoi);
            node[cuoi].push_back(dau);
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
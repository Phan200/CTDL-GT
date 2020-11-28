#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
vector<int> node[10001];
vector<int> Sheep;
bool check[10001];
bool visit[10001];

int a[10001][10001];

void Init(int n){
    int k=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            ++k;
            if(j+1<n){
                node[k].push_back(k+1);
                node[k+1].push_back(k);
            }
            if(i+1<n){
                node[k].push_back(k+n);
                node[k+n].push_back(k);
            }
        }
    }
}
void NotConnect(int x,int y){
    vector<int>::iterator it;
    for(it=node[x].begin();it!=node[x].end();++it){
        if(*it==y){
            node[x].erase(it);
            return;
        }
    }
}


void BFS(int s){
    queue<int> q;
    check[s]=false;
    q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        vector<int>::iterator it;
        for(it=node[u].begin();it!=node[u].end();++it){
            if(check[*it]){
                check[*it]=false;
                q.push(*it);
            }
        }
}
}
void Solve(){
    int res=0;
    memset(visit,1,sizeof(visit));
    vector<int>:: iterator it;
    vector<int>:: iterator k;
    for(it=Sheep.begin();it!=Sheep.end();++it){
        visit[*it]=false;
        memset(check,1,sizeof(check));
        BFS(*it);
        for(k=Sheep.begin();k!=Sheep.end();++k){
            if(visit[*k]&&check[*k]==true){
                ++res;
            }
        }
    }
    cout<<res<<endl;
}
int main(){
    int n,k,m;
    cin>>n>>k>>m;
    memset(a,1,sizeof(a));
    Init(n);

    for(int i=0;i<m;++i){
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        NotConnect(n*(x-1)+(y-1)+1,n*(a-1)+(b-1)+1);
        NotConnect(n*(a-1)+(b-1)+1,n*(x-1)+(y-1)+1);
    }
    
    
    for(int i=1;i<=k;++i){
        int a,b;
        cin>>a>>b;
        Sheep.push_back(n*(a-1)+(b-1)+1);
    }
    Solve();
}


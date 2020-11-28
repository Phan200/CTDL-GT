#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
vector<int> fr[100001];

bool check[100001];

void DFS(int u,int &res){
    ++res;
    check[u]=false;
    vector<int> ::iterator it;
    for(it=fr[u].begin();it!=fr[u].end();++it){
        if(check[*it]){
            DFS(*it,res);
        } 
    }
}
int VongTronBanBe(int n){
    memset(check,1,sizeof(check));
    int ans=-1;
    int res;
    for(int i=1;i<=n;++i){
        if(check[i]){
            res=0;
            DFS(i,res);
            ans=max(res,ans);
        }
    }
    if(ans!=-1) return ans;
    return 0;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i) fr[i].clear();
        for(int i=0;i<m;++i){
            int a,b;
            cin>>a>>b;
            fr[a].push_back(b);
            fr[b].push_back(a);
        }
        cout<<VongTronBanBe(n)<<endl;
    }
}
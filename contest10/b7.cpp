#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
vector<int> fr[100001];

bool check[100001];
bool KiemTra(int s,int u){
    vector<int>::iterator it;
    vector<int>::iterator pt;
    it=fr[s].begin();
    pt=fr[u].begin();
    while(it!=fr[s].end()&&pt!=fr[u].end()){
            if(*pt==s){
                ++pt;
            } 
            if(*it==u){
                ++it;
            }
            if(it==fr[s].end()) continue;
            if(*pt!=*it) return false; 
            ++pt;++it;
    }
    return true;
}

bool MangXH(int n){
    memset(check,1,sizeof(check));
    for(int i=1;i<=n;++i){
        check[i]=false;
        vector<int>::iterator it;
        for(it=fr[i].begin();it!=fr[i].end();++it){
            if(check[*it]){
                if(!KiemTra(i,*it)) return false; 
            }
        }
    }
    return true;
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
        for(int i=1;i<=n;++i){
            sort(fr[i].begin(),fr[i].end());
        }
        MangXH(n)? cout<<"YES\n": cout<<"NO\n";
    }
}
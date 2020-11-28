#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
vector<int> ed[1001];
int deg[1001];

int checkGraph(int v){
    int c=0;

    for(int i=1;i<=v;++i){
        if(deg[i]%2!=0){
            ++c;
        }
    }
    if(c==2) return 1;
    else if(c==0) return 2;
    else return 0; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        memset(deg,0,sizeof(deg));
        for(int i=1;i<=v;++i) ed[i].clear();
        for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            deg[a]++;
            deg[b]++;
        }
        cout<<checkGraph(v)<<"\n";
    }
}
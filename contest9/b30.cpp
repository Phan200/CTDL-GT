#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
vector<int> ed[1001];
int indeg[1001],outdeg[1001];

int checkGraph(int v){
    int a=0,b=0;

    for(int i=1;i<=v;++i){
        if(outdeg[i]!=indeg[i]) return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        memset(indeg,0,sizeof(indeg));
        memset(outdeg,0,sizeof(outdeg));
        for(int i=1;i<=v;++i) ed[i].clear();
        for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            outdeg[a]++;
            indeg[b]++;
        }
        cout<<checkGraph(v)<<"\n";
    }
}
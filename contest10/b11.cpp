/*
Prim:
B1: 
*/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<pair<int,int> > node[10001];

pair<int,int> minW(int v,bool check[]){
    int minD=INT_MAX;
    pair<int,int> ind;
    for(int i=1;i<=v;++i){
        if(!check[i]){
            vector<pair<int,int> >::iterator it;
            for(it=node[i].begin();it!=node[i].end();++it){
                pair<int,int> p=*it;
                if(check[p.first]&&minD>p.second){
                    minD=p.second;
                    ind=p;
                }
            }
        }
    }
    return ind;
}
void Prim(int n){
    bool check[n+1];
    memset(check,1,sizeof(check));
    int d=0;
    int k=0;
    check[1]=false;
    while(k<n-1){
        pair<int,int> e=minW(n,check);
        d+=e.second;
        check[e.first]=false;
        ++k;
    }
    cout<<d<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        for(int i=1;i<=v;++i) node[i].clear();
        for(int i=0;i<e;++i){
            int a,b,w;
            cin>>a>>b>>w;
            node[a].push_back(make_pair(b,w));
            node[b].push_back(make_pair(a,w));
        }
        Prim(v);
    }
}
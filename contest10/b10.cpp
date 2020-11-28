
#include<iostream>
#include<queue>
#include<algorithm>


using namespace std;
struct Edge{
    int b,e,w;
};

int root[10001];
Edge edge[10001];
bool Comp(Edge a,Edge b){
    return a.w<b.w;
}
int Find(int a){
    while(a!=root[a]) a=root[a];
    return a;
}

void Union(int x,int y){
    root[x]=y;
}
void Kruskal(int v){
    for(int i=1;i<=v;++i){
        root[i]=i;
    }
    int d=0;
    int k=0,i=0;
    while(k<v-1){
        int a=Find(edge[i].b);
        int b=Find(edge[i].e);
        if(a!=b){
            Union(a,b);
            d+=edge[i].w;
            ++k;
        }
        ++i;
    }
    cout<<d<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        for(int i=0;i<e;++i){
            cin>>edge[i].b>>edge[i].e>>edge[i].w;
        }
        sort(edge,edge+e,Comp);
        Kruskal(v);
    }
}

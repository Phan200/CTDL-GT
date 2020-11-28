#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int> >ed;
int root[1001];

int Find(int a){
    while(a!=root[a]) a=root[a];
    return a;
}
void Union(int a,int b){
    int x=Find(a);
    int y=Find(b);
    root[y]=x;
}
bool isCyclic(int e){
    vector<pair<int,int> > :: iterator it;
    for(it=ed.begin();it!=ed.end();++it){
        pair<int,int> x=*it;
        if(Find(x.first)!=Find(x.second)) Union(x.first,x.second);
        else return true;
    }
    return false;
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
        for(int i=1;i<=v;++i) {
            root[i]=i;
        }
        ed.clear();
        for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            ed.push_back({a,b});
        }
        if(isCyclic(v)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}
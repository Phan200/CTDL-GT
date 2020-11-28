#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
vector<int> edge[1001];
bool check[1001];
int root[1001];

int Find(int a){
    while(a!=root[a]) a=root[a];
    return a;
}
void Union(int a,int b){
    int x=root[a];
    int y=root[b];
    root[y]=x;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        int stop=0;
        cin>>n;
        memset(check,1,sizeof(check));
        for(int i=1;i<=n;++i) {
            edge[i].clear();
            root[i]=i;
        }
        for(int i=1;i<n;++i){
            int a,b;
            cin>>a>>b;
            check[a]=check[b]=false;
            if(Find(a)!=Find(b)){
                Union(a,b);
            } else {
                cout<<"NO\n";
                stop=1;
                break;
            }
        }
        if(stop==0){
            for(int i=1;i<=n;++i){
                if(check[i]){
                    cout<<"NO\n";
                    stop=1;
                    break;
                }
            }
        }
        if(stop==0) cout<<"YES\n";
    
    }
    
}
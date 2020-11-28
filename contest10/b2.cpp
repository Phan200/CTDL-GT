#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
bool check[15];
int ok;
vector<int> edge[1001];

void Hamilton(int v,int t, int k){
    check[t]=false;
    if(k==v){
        ok=1;
    } else {
        vector<int> :: iterator it;
        for(it=edge[t].begin();it!=edge[t].end();++it){
            if(check[*it]) {
                Hamilton(v,*it,k+1);
            }
        }
    }
    check[t]=true;    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        for(int i=1;i<=v;++i) edge[i].clear();
        for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        ok=0;
        for(int i=1;i<=v;++i){
            memset(check,1,sizeof(check));
            Hamilton(v,i,1);
            if(ok==1) {
                break;
            }
        }
        cout<<ok<<endl;         
    }
}
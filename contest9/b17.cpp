#include<bits/stdc++.h>

using namespace std;
vector<int> e[1005];
int check[1005];
void DFS(int u,int n){
    check[u]=false;
    for(int i=0;i<e[u].size();++i){
        if(check[e[u][i]]){
            DFS(e[u][i],n);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cin.ignore();
        string str;
        getline(cin,str);
        istringstream my_str(str);
        while (my_str)
        {
            int dau,cuoi;
            my_str>>dau>>cuoi;
            e[dau].push_back(cuoi);
        }
        int stop=0;
        
        for(int i=1;i<=n;++i){
            memset(check,1,sizeof(check));
            DFS(i,n);
            for(int j=1;j<=n;++j){
                if(check[j]) {
                    stop=1;
                    break;
                }
            }
            if(stop==1) break;
        }

        if(stop==1) cout<<"NO\n";
        else cout<<"YES\n";
    }
}
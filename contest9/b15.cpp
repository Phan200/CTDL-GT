#include<iostream>
#include<string>
#include<sstream>
#include<cstring>

using namespace std;
int G[1001][1001];
int check[1001];
void DFS(int u,int n){
    check[u]=false;
    for(int i=1;i<=n;++i){
        if(check[i]&&G[u][i]==1){
            DFS(i,n);
        }
    }
}
int duyetLienThong(int n){
    int res=0;
    for(int i=1;i<=n;++i){
        if(check[i]){
            ++res;
            DFS(i,n);
        }
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        memset(G,0,sizeof(G));
        memset(check,1,sizeof(check));
        cin.ignore();
        string str;
        getline(cin,str);
        istringstream my_str(str);
        while (my_str)
        {
            int dau,cuoi;
            my_str>>dau>>cuoi;
            G[dau][cuoi]=G[cuoi][dau]=1;
        }
        int res=duyetLienThong(n);
        cout<<res<<endl;
    }
}
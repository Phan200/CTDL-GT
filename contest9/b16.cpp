#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
#include<queue>

using namespace std;
int G[1001][1001];
int check[1001];
void BFS(int u,int n){
    queue<int> qu;
    qu.push(u);
    check[u]=false;
    while(!qu.empty()){
        int top=qu.front();
        qu.pop();
        for(int i=1;i<=n;++i){
            if(check[i]&&G[top][i]==1){
                qu.push(i);
                check[i]=false;
            }
        }
    }
}
int duyetLienThong(int n){
    int res=0;
    for(int i=1;i<=n;++i){
        if(check[i]){
            ++res;
            BFS(i,n);
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
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstring> 

using namespace std;
bool check[10001];
vector<int> ke[10001];

void DFS(int u){
    check[u]=false;
    cout<<u<<" ";
    for(int i=0;i<ke[u].size();++i){
        if(check[ke[u][i]]){
            check[ke[u][i]]=false;
            DFS(ke[u][i]);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e,u;
        cin>>v>>e>>u;
        for(int i=1;i<=v;++i) ke[i].clear();
        cin.ignore();
        string str;
        getline(cin,str); 
        istringstream my_str(str);
        int dau,cuoi;
        while(my_str){
            my_str>>dau>>cuoi;
            ke[dau].push_back(cuoi);
        }
        
        memset(check,1,sizeof(check));
        DFS(u);
        cout<<endl;
    }
}
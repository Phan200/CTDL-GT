#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstring> 


using namespace std;
bool check[10001];
vector<int> ke[10001];
int truoc[1001];


void print(int truoc[], int s,int i){
    if(truoc[i]==s){
        cout<<s<<" ";
        return;
    }
    print(truoc,s,truoc[i]);
    cout<<truoc[i]<<" ";
}
void DFS(int u){
    check[u]=false;
    for(int i=0;i<ke[u].size();++i){
        if(check[ke[u][i]]){
            truoc[ke[u][i]]=u;
            DFS(ke[u][i]);
        }
    }
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e,u,s,t;
        cin>>v>>e>>s>>t;
        for(int i=1;i<=v;++i) ke[i].clear();
        cin.ignore();
        string str;
        getline(cin,str); 
        istringstream my_str(str);
        int dau,cuoi;
        while(my_str){
            my_str>>dau>>cuoi;
            ke[dau].push_back(cuoi);
            ke[cuoi].push_back(dau);
        }
        
        memset(check,1,sizeof(check));
        DFS(s);
        if(!check[t]){
            print(truoc,s,t);
            cout<<t<<endl;
        } else cout<<-1<<endl;
    }
}
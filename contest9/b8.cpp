#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include<queue>

using namespace std;
vector<int> ke[1001];
bool check[1001];
void BFS(int s){
    queue<int> qu;
    qu.push(s);
    check[s]=false;
    while (!qu.empty())
    {
        int top=qu.front();
        qu.pop();
        cout<<top<<" ";
        for(int i=0;i<ke[top].size();++i){
            if(check[ke[top][i]]){
                qu.push(ke[top][i]);
                check[ke[top][i]]=false;
            }
        }
    }
    

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int v,e,u;
        cin>>v>>e>>u;
        cin.ignore();
        for(int i=1;i<=v;++i) ke[i].clear();
        string str;
        getline(cin,str);
        istringstream my_str(str);
        while(my_str){
            int dau,cuoi;
            my_str>>dau>>cuoi;
            ke[dau].push_back(cuoi);
            ke[cuoi].push_back(dau);
        }
        memset(check,1,sizeof(check));
        BFS(u);
        cout<<endl;
    }
}
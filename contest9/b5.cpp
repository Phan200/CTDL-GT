#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
    
    int v,e,i,j;
    cin>>v>>e;
    vector<int> ke[v+1];
   
    for(i=0;i<e;++i){
        int node,end;
        cin>>node>>end;
        ke[node].push_back(end);
    }
    for(i=0;i<v;++i){
        cout<<i<<": ";
        for(j=0;j<ke[i].size();++j){
            cout<<ke[i][j]<<" ";
        }
        cout<<endl;
    }
    }
}
#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long int
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        ll v,e;
        cin>>v>>e;
        vector<int> Ke[10001];
        
        for(ll i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            Ke[a].push_back(b);
            Ke[b].push_back(a);
        }
        for(ll i=0;i<v;++i){
            cout<<i<<": ";
            sort(Ke[i].begin(),Ke[i].end());
            for(ll j=0;j<Ke[i].size();j++){
                cout<<Ke[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
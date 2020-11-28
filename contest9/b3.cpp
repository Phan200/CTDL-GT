#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n;
    cin>>n;
    
    for(int i=0;i<n;++i){
        int so;
        vector<int> ke; 
        for(int j=0;j<n;++j){
            cin>>so;
            if(so==1) ke.push_back(j);
        }
    
        for(int j=0;j<ke.size();++j){
            cout<<ke[j]+1<<" ";
        }
        cout<<endl;
    }
}
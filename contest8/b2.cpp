#include<iostream>
#include<queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    string lenh;
    queue<int> qu;
    while(t--){
        cin>>lenh;
        if(lenh=="PUSH"){
            int number;
            cin>>number;
            qu.push(number);
        } else if(lenh=="PRINTFRONT"){
            if(!qu.empty()) cout<<qu.front()<<endl;
            else cout<<"NONE"<<endl;
        } else {
            if(!qu.empty()) qu.pop();
        }
    }
}

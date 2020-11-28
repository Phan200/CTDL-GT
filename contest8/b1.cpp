#include<iostream>
#include<queue>

using namespace std;
int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        queue<int> qu;
        int lenh,number;
        while(n--){
            cin>>lenh;
            if(lenh==3){
                cin>>number;
                qu.push(number);
               
            } else if(lenh==2){
                if(qu.empty()){
                    cout<<"YES\n";
                } else cout<<"NO\n";
            } else if(lenh==1){
                cout<<qu.size()<<endl;
                 
            } else if(lenh==4){
                if(!qu.empty()) qu.pop();
               
            } else if(lenh==5){
                if(!qu.empty()) cout<<qu.front()<<endl;
                else cout<<-1<<endl;
            } else if(lenh==6){
                if(!qu.empty()) cout<<qu.back()<<endl;
                else cout<<-1<<endl;
            }
        }
        if(lenh==3||lenh==4) cout<<endl;
    }
    
}
#include<iostream>
#include<queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    string lenh;
    deque<int> dq;
    while(t--){
        int number;
        cin>>lenh;
        if(lenh=="PUSHFRONT"){
            cin>>number;
            dq.push_front(number);
        } else if(lenh=="PRINTFRONT"){
            if(!dq.empty()) cout<<dq.front()<<endl;
            else cout<<"NONE"<<endl;
        } else if(lenh=="POPFRONT"){
            if(!dq.empty()) dq.pop_front();
        } else if(lenh=="PUSHBACK"){
            cin>>number;
            dq.push_back(number); 
        } else if(lenh=="PRINTBACK"){
            if(!dq.empty()) cout<<dq.back()<<endl;
            else cout<<"NONE"<<endl;
        } else {
            if(!dq.empty()) dq.pop_back();
        }
    }
}

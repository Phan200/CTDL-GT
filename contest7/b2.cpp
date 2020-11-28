#include<iostream>
#include<stack>

using namespace std; 
int main(){
    
    stack<int> s;
    int n;
    cin>>n;
    while(n--){
        string str="";
        cin>>str;
        if(str=="PUSH"){
            int number;
            cin>>number;
            s.push(number);
        } else if(str=="POP"){
            if(!s.empty()) s.pop();
        } else if(str=="PRINT"){
            if(!s.empty()) cout<<s.top()<<endl;
            else cout<<"NONE"<<endl;
        } 
    }
}
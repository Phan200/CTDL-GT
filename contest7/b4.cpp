#include<iostream>
#include<stack>

using namespace std; 

int main(){
    
    int t;
    cin>>t;
    while(t--){
        
        string str;
        cin>>str;
        stack<char> s;
        bool ok=1;
        
        for(int i=0;i<str.length();++i){
            if(str[i]=='('||str[i]=='['||str[i]=='{'){
                s.push(str[i]);
            } else if(str[i]==')'){
                if(s.empty()) {
                    ok=0;
                    break;
                }
                if(s.top()=='(') s.pop();
            } else if(str[i]==']'){
                if(s.empty()){
                    ok=0;
                    break;
                }
                if(s.top()=='['){
                    s.pop();
                }
            } else if(str[i]=='}'){
                if(s.empty()) {
                    ok=0;
                    break;
                }  
                if(s.top()=='{'){
                    s.pop();
                }
            }
        }
        if(s.empty()&&ok==1) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
}

#include<iostream>
#include<stack>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin.ignore();
        string str;
        cin>>str;
        
        stack<int> s;
        s.push(0);
        
        for(int i=0;i<str.length();++i){
            
            if(str[i]=='+'){
                if(s.top()==0){
                    str[i]='+';
                } else if(s.top()==1) str[i]='-';
            } else if(str[i]=='-'){
                if(s.top()==0){
                    str[i]='-';
                } else if(s.top()==1) str[i]='+';
            } else if(str[i]=='('){
                if(i-1>=0&&str[i-1]=='-'){
                    s.push(1);
                }
                if(i-1>=0&&str[i-1]=='+') s.push(0);
            } else if(str[i]==')') s.pop();
            
        }
        for(int i=0;i<str.length();++i){
            if(str[i]!='('&&str[i]!=')'){
                cout<<str[i];
            }
        }
        cout<<endl;
    }
}
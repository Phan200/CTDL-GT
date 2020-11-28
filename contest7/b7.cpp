#include<iostream>
#include<stack>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        stack<char> s;
        int res=0;
        int l=str.length()-1;
        
        for(int i=0;i<=l;++i){
            if(str[i]==')'&&!s.empty()){
                if(s.top()=='(') s.pop();
                else s.push(')');
            } else s.push(str[i]);
        }
        
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(top==s.top()){
                ++res;
            } else {
                res+=2;
            }
            s.pop();
        }
        cout<<res<<endl;
    }
}

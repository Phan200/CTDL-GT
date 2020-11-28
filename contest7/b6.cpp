#include<iostream>
#include<stack>

using namespace std; 
bool check(string str){
    stack<char>s;
    for(auto&ch : str){
        if(ch==')'){
            char top=s.top();
            s.pop();
            bool flag=1;
            while(top!='('){
                if(top=='+'||top=='-'||top=='*'||top=='/'){
                    flag=0;
                }
                top=s.top();
                s.pop();
            }
            if (flag) return true;
        }
        else s.push(ch);
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        if(check(str)) cout<<"Yes\n";
        else cout<<"No\n";
    }
}

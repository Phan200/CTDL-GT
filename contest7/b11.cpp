#include<iostream>
#include<stack>
#include<vector>

using namespace std;
int degree(char c){
    if(c=='^') return 5;
    if(c=='*'||c=='/') return 4;
    if(c=='+'||c=='-') return 3;
    return 2;
}
void Solve(string p){
    stack<char> st;
    string a="";
    st.push('0');

    for (int i = 0; i < p.length(); i++)
    {
        if(p[i]=='('){
            st.push(p[i]);
        } else if (p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/'||p[i]=='^'){
            while(st.top()!='0'&&degree(st.top())>=degree(p[i])){
                char c=st.top();
                st.pop();
                a+=c;
            }
            st.push(p[i]);
        } else if(p[i]==')'){
            while(st.top()!='0'&&st.top()!='('){
                char c=st.top();
                st.pop();
                a+=c;
            }
            st.pop();
        } else {
            a+=p[i];
        }
    }
    while(st.top()!='0'){
        if(st.top()!='('){
            char c=st.top();
            a+=c;
        }
        st.pop();
    }

    cout<<a<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solve(s);
    }
}
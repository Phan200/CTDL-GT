#include<iostream>
#include<stack>
#include<vector>

using namespace std; 

void Solve(string p){
    stack<string> st;

    for(int i=p.length()-1;i>=0;--i){
        if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/'||p[i]=='^'){
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string temp="("+s1+p[i]+s2+")";
            st.push(temp);
        } else{
            st.push(string(1,p[i]));
        }
    }
    cout<<st.top()<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solve(s);
    }
}

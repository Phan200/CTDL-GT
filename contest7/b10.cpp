#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;
string Solve(string p){
    stack<int> s;
    string res="";
    s.push(0);
    for(int i=0;i<p.length();++i){
        if(p[i]=='+'){
            if(s.top()==0){
                p[i]='+';
            } else p[i]='-';
        } else if(p[i]=='-'){
            if(s.top()==0){
                p[i]='-';
            } else p[i]='+';
        } else if(p[i]=='('){
            if(i-1>=0&&p[i-1]=='+'){
                s.push(0);
            } else if(i-1>=0&&p[i-1]=='-'){
                s.push(1);
            }
        } else if(p[i]==')') s.pop();
        if(p[i]!='('&&p[i]!=')'){
            res+=p[i];
        }
    }
    return res;
}

int main(){
    int t;cin>>t;
    while(t--){
        string p1,p2;
        cin>>p1;
        cin>>p2;
        p1=Solve(p1);
        p2=Solve(p2);
        if(p1==p2) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
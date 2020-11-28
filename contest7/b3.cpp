#include<iostream>
#include<stack>
#include<string>

using namespace std; 

int main(){

    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string str="";
        getline(cin,str);
        
        string res="";
        stack<char> s;
        
        for(int i=0;i<str.length();++i){
            if(str[i]!=' '){
                s.push(str[i]);
            } else{
                while(!s.empty()){
                    cout<<s.top();
                    s.pop();
                }
                cout<<" ";
            }
        }
        while(!s.empty()){
                    cout<<s.top();
                    s.pop();
                }
        cout<<endl;
    }
}

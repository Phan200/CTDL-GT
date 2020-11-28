/*
1) Create an empty stack and push -1 to it. The first element
   of the stack is used to provide a base for the next valid string. 

2) Initialize result as 0.

3) If the character is '(' i.e. str[i] == '('), push index 
   'i' to the stack. 
   
2) Else (if the character is ')')
   a) Pop an item from the stack (Most of the time an opening bracket)
   b) If the stack is not empty, then find the length of current valid
      substring by taking the difference between the current index and
      top of the stack. If current length is more than the result,
      then update the result.
   c) If the stack is empty, push the current index as a base for the next
      valid substring.

3) Return result.
*/

#include<iostream>
#include<stack>

using namespace std; 

int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        stack<int> s;
        int res=0;
        
        s.push(-1);
        for(int i=0;i<str.length();++i){
            if(str[i]=='('){
                s.push(i);
            } else {
                s.pop();// loai chi so cua ngoac mow truoc
                if(!s.empty()){
                    res=max(res,i-s.top());
                } else s.push(i);
            } 
        }
   
        cout<<res<<endl;  
    }
}


#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> s;
    //s.push(-1);
    do
    {
        string lenh;
        int number,str;
        cin>>lenh;
        if(lenh=="push") {
            cin>>number;
            s.push(number);
        } else if(lenh=="show"){
            int n=s.size();
            int a[n];
            for(int i=n-1;i>=0;--i){
                a[i]=s.top();
                s.pop();
            }
            for(int i=0;i<n;++i){
                cout<<a[i]<<" ";
                s.push(a[i]);
            }
            cout<<endl;
        } else if(lenh=="pop"){
            s.pop();
        }
        
    } while (!s.empty());
    cout<<"empty"<<endl;
    
}
#include<iostream>
#include<queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        queue<string> qu;
        qu.push("1");
        while(n--){
            string str1=qu.front();
            qu.pop();
            string str2=str1;

            cout<<str1<<" ";
            qu.push(str1.append("0"));
            qu.push(str2.append("1"));
        }
        cout<<endl;
    }
}

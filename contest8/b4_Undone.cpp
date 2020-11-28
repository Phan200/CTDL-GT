#include<iostream>
#include<queue>
#include<sstream>
#include <cstring>

using namespace std; 
int a[60]={0};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int k;
        string str;
        cin>>k>>str;
        priority_queue<int> pq;
        memset(a,0,sizeof(a));
        for(auto ch:str){
            //cout<<ch-'0'<<endl;
            a[ch-'0']++;
        }
        for(int i=17;i<60;++i) pq.push(a[i]);
        int top;
        while(k--){
            top=pq.top();
            pq.pop();
            top-=1;
            pq.push(top);
        }
        top=pq.top();
        pq.pop();
        int res=0;
        while(top!=0){
            res+=top*top;
            top=pq.top();
            pq.pop();
        }
        cout<<res<<endl;
    }
}

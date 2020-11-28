/*
(a) -1
(b) *2
3 7 :
3-1=2; 2*2=4; 4*2=8;8-1=7;

*/

#include<iostream>
#include<queue>
#include<set>


using namespace std;

struct node{
    int v,level;
};
int Solve(int s,int t){
    queue<node> q;
    set<int> check;
    node n={s,0};
    q.push(n);
    node top;

    while(!q.empty()){
        top=q.front();
        q.pop();
        if(top.v==t) return top.level;
        
        if(top.v*2==t||top.v-1==t) return top.level+1;
        if(check.find(top.v*2)==check.end()){
            n.v=top.v*2;
            n.level=top.level+1;
            q.push(n);
            check.insert(n.v);
        }
        if(top.v-1>=0&&check.find(top.v-1)==check.end()){
            n.v=top.v-1;
            n.level=top.level+1;
            q.push(n);
            check.insert(n.v);
        }
    }
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int s,t;
        cin>>s>>t;
        cout<<Solve(s,t)<<endl;
    }
}
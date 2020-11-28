#include<iostream>
#include<queue>
#include<set>
#include<math.h>

struct Node{
    int value,level;
};
using namespace std; 


int Find(int x){
    int res=-1;
    for(int i=sqrt(x);i>=2;--i){
        if(x%i==0){
            res=x/i;
            break;
        }
    }
    return res;
} 
int Solve(int n){
    queue<Node> q;
    set<int> check;
    Node x={n,0};
    q.push(x);
    Node t;
    
    while(!q.empty()){
        t=q.front();
        q.pop();
        if(t.value==1) return t.level;
        if(t.value-1==1) return t.level+1;
        int k=Find(t.value);
        if(t.value-1>=0&&check.find(t.value-1)==check.end()){
            x.value=t.value-1;
            x.level=t.level+1;
            q.push(x);
            check.insert(x.value);
        }
        if(k!=-1&&check.find(k)==check.end()){
            x.value=k;
            x.level=t.level+1;
            q.push(x);
            check.insert(x.value);
        }        
    }
    return t.level;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    //Init();
    while(t--){
        int n;
        cin>>n;
        cout<<Solve(n)<<endl;
    }
}

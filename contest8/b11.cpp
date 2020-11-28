#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
#include<cstring>


using namespace std; 
vector<int> Prime;
vector<int> edge[10001];
int visit[10001];
int dis[10001];

void isPrime(){
    for(int i=1000;i<=9999;++i){
        int dem=0;
        for(int j=2;j<=sqrt(i);++j){
            if(i%j==0)++dem;
        }
        if(dem==0) Prime.push_back(i);
    }
}
bool check(int a,int b){
    int c=0;
    while(a){
        if(a%10!=b%10) ++c;
        a/=10;b/=10;
    }
    if(c==1) return true;
    else return false;
} 
void List(){
        for(int j=i+1;j<Prime.size();++j){
            int a=Prime[i];
            int b=Prime[j];
            if(check(a,b)){
                edge[a].push_back(b);
                edge[b].push_back(a);
            }
        }
    }
}
void BFS(int s){
    memset(dis,0,sizeof(dis));
    memset(visit,0,sizeof(visit));
    queue<int> q;
    q.push(s);
    visit[s]=1;
    dis[s]=0;
    while (!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=0;i<edge[t].size();++i){
            int x=edge[t][i];
            if(visit[x]==0){
                visit[x]=1;
                q.push(x);
                dis[x]=dis[t]+1;
            }
        }
    }
    

}
int main(){
    isPrime();
    List();
    int t;
    cin>>t;
    while(t--){
        int s,t;
        cin>>s>>t;
        BFS(s);
        cout<<dis[t]<<endl;
    }
}

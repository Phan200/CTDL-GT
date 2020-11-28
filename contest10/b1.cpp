/*
Su dung tham lam hoac quay lui

*/

#include<iostream>
#include<vector>
#include<cstring>


using namespace std;
vector<int> edge[1001];

bool Greedy_Coloring(int v,int color){
    int res[v+1];// ghi nhan mau cua dinh
    memset(res,0,sizeof(res));

    bool check[color+1]; 
    res[1]=1; // gan dinh dau tien cho 1 mau 
    for(int i=2;i<=v;++i){
        memset(check,0,sizeof(check));
        vector<int>:: iterator it;
        for(it=edge[i].begin();it!=edge[i].end();++it){
            // kiem tra cac dinh ke voi no co mau gi
            // va loai cac mau do ra
            if(res[*it]!=0){
                check[res[*it]]=true;// mau da duoc to
            }
        }
        int paint;
        for(paint=1;paint<=color;++paint){
            // tim mau phu hop voi yeu cau
            if(!check[paint]){
                res[i]=paint;
                break;
            } 
        }
        if(res[i]==0) return false;
        
    }
    
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int v,e,color;
        cin>>v>>e>>color;
        for(int i=1;i<=v;++i) edge[i].clear();
        
        for(int i=0;i<e;++i){
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        
        if(Greedy_Coloring(v,color)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

/*
Su dung thuat toan Welsh Powell
*/

// #include<iostream>
// #include<vector>
// #include<cstring>
// #include<queue>

// using namespace std;

// vector<int> edge[1001];

// bool BFS(int v, int color) 
// { 
//     int result[v+1]; 
//     memset(result,0,sizeof(result));
//     bool check[color+1],visit[v+1];
    
//     memset(visit,1,sizeof(visit));
//     queue<int> q;
//     q.push(1);
//     visit[1]=false;
//     while (!q.empty())
//     {
//         int u=q.front();
//         q.pop();
//         vector<int> ::iterator it;
//         memset(check,1,sizeof(check));
//         for(it=edge[u].begin();it!=edge[u].end();++it){
//             if(result[*it]!=0){
//                 check[result[*it]]=false; 
//             }
//             if(visit[*it]){
//                 visit[*it]=false;
//                 q.push(*it);
//             }
//         }
//         for(int paint=1;paint<=color;++paint){
//             // tim mau phu hop voi yeu cau
//             if(check[paint]){
//                 result[u]=paint;
//                 break;
//             } 
//         }
//         if(result[u]==0) return false;        
//     }
//     return true;
// } 
// int main(){
//     ios_base::sync_with_stdio(false);cin.tie(NULL);
//     int t;cin>>t;
//     while(t--){
//         int v,e,color;
//         cin>>v>>e>>color;
//         for(int i=1;i<=v;++i) edge[i].clear();
//          for(int i=0;i<e;++i){
//             int a,b;
//             cin>>a>>b;
//             edge[a].push_back(b);
//             edge[b].push_back(a);
//         }
//         if(BFS(v,color)) cout<<"YES\n";
//         else cout<<"NO\n";
        
//     }
//     return 0;
// }
#include<bits/stdc++.h>

using namespace std;

vector<int> node[250005];
bool check[250005];
int turn=0;
int change;
bool ok;
int f;
int n,m;

void addEdge(int x, int y){
    node[x].push_back(y);
    node[y].push_back(x);
}
void DFS(int s,int t){
    check[s]=false;
    vector<int> ::iterator it;
    for(it=node[s].begin();it!=node[s].end();++it){
        if(f==1){// co dinh lan dau cua change de so sanh
            f=0;
            change=abs(*it-s);
        }
      if(ok==0){
        if(turn>2){
            turn-=1;
            //change==1? change=m:change=1;
            check[s]=true;
            return;
        }// neu so lan chuyen huong vuot 2 thi loai
        if(turn<=2&&*it==t) {// neu so lan chuyen huong khong vuot qua 2 va cham dich
            ok=1;
            return;
        }
        
        if(check[*it]){ // neu chua cham dich 
            if(abs(*it-s)!=change){// kiem tra xem co chuyen huong khong
                ++turn;// tang so luot chuyen
                change=abs(*it-s);
                DFS(*it,t);
                --turn;
            } else DFS(*it,t);
            
        } 
      } else break;
    }
    check[s]=true;
    if(ok) return;
    
}
void FindThePath(int s, int t){
    ok=0;
    f=1;
    turn =0;
    memset(check,1,sizeof(check));
    DFS(s,t);
    ok==1? cout<<"YES\n": cout<<"NO\n";

}
int main(){
    int t;cin>>t;
    while(t--){
        
        cin>>n>>m;
        int s, t;
        char a[n][m];
        for(int i=1;i<=n*m;++i) node[i].clear();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>a[i][j];
                if(a[i][j]=='S'){
                    s=i*m+j+1;
                } 
                if(a[i][j]=='T'){
                    t=i*m+j+1;
                }
            }
        }
        int k=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                k++; 
                if(a[i][j]!='*'){
                   if(j+1<m&&a[i][j+1]!='*'){
                        addEdge(k,k+1);
                    }                    
                    if(i+1<n&&a[i+1][j]!='*'){
                        addEdge(k,k+m);
                    }
                    
                } 
                 
            }
        }
        for(int i=1;i<k;++i){
            sort(node[i].begin(),node[i].end());
        }
        FindThePath(s,t);
    }

}
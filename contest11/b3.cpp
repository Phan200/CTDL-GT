/*
Inorder duyet theo thu tu truoc LNR
Preorder duyet theo thu tu giua NLR
Postorder duyet theo thu tu sau LRN
10
3 2 5 1 9 6 10 4 7 8
1 2 3 5 4 6 9 10 7 8
3 5 2 9 10 6 8 7 4 1
13
20 25 28 30 32 35 38 40 50 60 65 70 90
40 30 25 20 28 35 32 38 60 50 70 65 90
20 28 25 32 38 35 30 50 65 90 70 60 40
*/
#include<iostream>
using namespace std;

int preInd=0;
int TimNode(int in[],int s,int e, int data){
    int i=0;
    for(i=s;i<e;++i){
        if(in[i]==data){
            return i;
        }
    }
    return i;
}
void PostOrder(int in[],int pre[],int s,int e,int n){
    if(s>e||s>=n) return;
    int inInd=TimNode(in,s,e,pre[preInd++]);
    PostOrder(in,pre,s,inInd-1,n);
    PostOrder(in,pre,inInd+1,e,n);
    cout<<in[inInd]<<" ";
}
int main(){
    int t;cin>>t;
    while(t--){
        preInd=0;
        int n;
        cin>>n;
        int in[n],pre[n];
        for(int i=0;i<n;++i){
            cin>>in[i];
        }
        for(int i=0;i<n;++i){
            cin>>pre[i];
        }
        PostOrder(in,pre,0,n,n);
        cout<<endl;
    }
}
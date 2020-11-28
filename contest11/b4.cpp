/*
Inorder duyet theo thu tu truoc LNR
Preorder duyet theo thu tu giua NLR
Postorder duyet theo thu tu sau LRN
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void Find(ll pre[],int n,ll maxval,ll minval, int &ind){
    if(ind==n) return;
    if(pre[ind]>maxval||pre[ind]<minval){
        return;
    }
    ll val=pre[ind];
    ++ind;
    Find(pre,n,val,minval,ind);
    Find(pre,n,maxval,val,ind);
    cout<<val<<" ";
}
void PostOrder(ll pre[],int n){
    int ind=0;
    Find(pre,n,10001,0,ind);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll pre[n];
        for(int i=0;i<n;++i) cin>>pre[i];
        PostOrder(pre,n);
        cout<<endl;

    }
}
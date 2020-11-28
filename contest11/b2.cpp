/*
ex: +--+**+12345678
((1+2)-(3*4))+((5*6)-(7+8))
*/

#include<bits/stdc++.h>


using namespace std;
struct Node{
    string data;
    Node *l,*r;
};

bool check(char c){
    return(c=='+'||c=='-'||c=='*'||c=='/');
}

Node *TaoNode(string c){
    Node *p=new Node;
    p->l=p->r=NULL;
    p->data=c;
    return p;
}
Node *CayBieuThuc(string s[],int n){
    queue<Node*> qu;
    Node *t,*t1,*t2;
    Node *root;
    int dem=0;
    root=TaoNode(s[0]);
    ++dem;
    qu.push(root);

    while(!qu.empty()){
        t=qu.front();qu.pop();
        if(dem!=n){
            t1=TaoNode(s[dem]);
            t->r=t1;
            ++dem;
            qu.push(t1);
        } else{
            t->r=NULL;
        }
        if(dem!=n){
            t2=TaoNode(s[dem]);
            t->l=t2;
            ++dem;
            qu.push(t2);
        } else{
            t->l=NULL;
        }
    }
    return root;
}
long long So(string s){
    long long ans=0;
    if(s[0]=='-'){
        s.erase(0,1);
        for(int i=0;i<s.length();++i){
            ans=ans*10+s[i]-'0';
        }
        return -ans;
    } else{
        for(int i=0;i<s.length();++i){
            ans=ans*10+s[i]-'0';
        }
        return ans;
    }
}
long long TinhToan(Node *Cay){
    if(Cay->data!="+"&&Cay->data!="-"&&Cay->data!="*"&&Cay->data!="/"){
        return So(Cay->data);
    }
    if(Cay->data=="+"){
        return TinhToan(Cay->r)+TinhToan(Cay->l);
    }
    if(Cay->data=="-"){
        return TinhToan(Cay->r)-TinhToan(Cay->l);
    }
    if(Cay->data=="*"){
        return TinhToan(Cay->r)*TinhToan(Cay->l);
    }
    return TinhToan(Cay->r)/TinhToan(Cay->l);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str[n];
        for(int i=0;i<n;++i){
            cin>>str[i];
        }
        Node* p;
        p=CayBieuThuc(str,n);
        cout<<TinhToan(p)<<endl;
    }
}
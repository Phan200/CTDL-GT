#include<bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    Node *l,*r;

    Node(int x){
        data=x;
        l=r=NULL;
    }
};

void Solve(Node *root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *n=q.front();q.pop();
        cout << n->data <<" ";
        if(n->l != NULL) q.push(n->l);
        if(n->r != NULL) q.push(n->r);
    }
}

void newNode(Node *root,int a,int b, char c){
    switch (c)
    {
    case 'L':
        root->l=new Node(b);
        break;
    case 'R':
        root->r=new Node(b);
        break;
    default:
        break;
    }
}
void insert(Node *root, int a,int b,char c){
    if(root==NULL){
        return;
    }
    if(root->data==a){
        newNode(root,a,b,c);
    } else {
        insert(root->l,a,b,c);
        insert(root->r,a,b,c);
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        Node *root=NULL;
        while(n--){
            int a,b;
            char c;
            cin>>a>>b>>c;
            if(root==NULL){
                root= new Node(a);
                newNode(root,a,b,c);
            } else {
                insert(root,a,b,c);
            }
        }
        Solve(root);
    }
}
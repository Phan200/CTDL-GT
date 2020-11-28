#include<iostream>
#include<stack>

using namespace std;

struct Node{
    char data;
    Node *l,*r;// con tro den node con ben trai va node con ben phai
};
// kiem tra xem ki tu c co phai phep toan khong
Node *TaoNode(char c){
    Node *p=new Node;
    p->l=p->r=NULL;
    p->data=c;
    return p;
}
bool check(char c){
    return(c == '-' || c == '+' || c == '*' || c == '/' || c == '^'); 
}
void print(Node *t){
    if(t!=NULL){
        print(t->l);
        cout<<t->data<<" ";
        print(t->r);
    }
}
Node *CayBieuThuc(string s){
    stack<Node*> st;
    Node *t,*so_1,*so_2;
    for(int i=0;i<s.length();++i){
        if(!check(s[i])){// neu s[i] la toan hang
            t=TaoNode(s[i]);
            st.push(t); 
        } else {// s[i] la phep toan
            t=TaoNode(s[i]);
            so_1=st.top();st.pop();
            so_2=st.top();st.pop();
            t->r=so_1;
            t->l=so_2;
            st.push(t);
        }
    }
    return st.top();
}
int main(){
    int t;cin>>t;
    while(t--){
        string str;
        cin>>str;
        Node *t=CayBieuThuc(str);
        print(t);
        cout<<endl;
    }
}
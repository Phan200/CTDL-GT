// dung linked list lam
#include<iostream>
#define ll long long int
using namespace std;

struct Node{
    int coeff,power;
    Node* next;
};
Node *addNew(Node* s, int coeff, int power){
    // tao node moi
    Node* n=new Node;
    n->coeff=coeff;
    n->power=power;
    n->next=NULL;
    // neu list rong
    if(s==NULL) return n;
    // neu list da co node
    Node* ptr=s;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=n;
    return s;
}
void Dup(Node *s){
    Node *ptr1,*ptr2,*dup;
    ptr1=s;
    while(ptr1!=NULL&&ptr1->next!=NULL){
        ptr2=ptr1;
        while (ptr2->next!=NULL)
        {
            if(ptr1->power==ptr2->next->power){
                ptr1->coeff+=ptr2->next->coeff;
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(dup);
            } else{
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}
Node* mul(Node* p1,Node* p2, Node *p3){
    Node *ptr1,*ptr2;
    ptr1=p1;
    ptr2=p2;
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            int coeff, power;
            coeff=ptr1->coeff*ptr2->coeff;
            power=ptr1->power+ptr2->power;
            p3=addNew(p3,coeff,power);

            ptr2=ptr2->next;
        }
        ptr2=p2;
        ptr1=ptr1->next;
    }
    Dup(p3);
    return p3;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int m,n;
        cin>>m>>n;
        Node *p1=NULL,*p2=NULL, *p3=NULL;;
        for(int i=0;i<m;++i){
            int a;
            cin>>a;
            p1=addNew(p1,a,i);
        }
        for(int i=0;i<n;++i){
            int a;
            cin>>a;
            p2=addNew(p2,a,i);
        }
        p3=mul(p1,p2,p3);
        while(p3!=NULL){
            cout<<p3->coeff<<" ";
            p3=p3->next;
        }
        cout<<endl;
    }
    
}
#include<iostream>
#include<algorithm>

using namespace std;
int n;
int *a,*b;
void Init(){
    a=new int[n];
    b=new int [n];
    for(int i=0;i<n;++i){
        cin>>a[i];
        b[i]=a[i];
    }
}
bool Sap_xep(){
    sort(b,b+n);
    for(int i=0;i<n;++i){
        if(a[i]!=b[i]&&a[i]!=b[n-i-1]) return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
       cin>>n;
       Init();
       if(Sap_xep()) cout<<"Yes";
       else cout<<"No";
       cout<<endl;
    }
    
}
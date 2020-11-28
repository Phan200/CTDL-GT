#include<iostream>
#include<algorithm>

using namespace std;
long long *a;
int n;
void init(){
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
}
void Ghep_So(){
    sort(a,a+n);
    long long x=0,y=0; // 2 so dc tao nen boi mang a[]
    for (int i = 0; i < n; i++)
    {
        if(i%2==0) x=x*10+a[i];
        else y=y*10+a[i];
    }
    cout<<x+y<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        a=new long long[n];
        init();
        Ghep_So();
    }
    
}
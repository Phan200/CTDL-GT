#include<bits/stdc++.h>

using namespace std;
void print(int k,int n,int a[]){
    cout<<"Buoc "<<k<<": ";
    for(int i=0;i<n;++i) cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int mark=a[0];
    for(int k=1;k<=n;++k){
        print(k-1,k,a);
        int x=a[k];
        for(int j=k-1;j>=0;--j){
            if(a[j]>x){
                a[j+1]=a[j];
                a[j]=x;
            } else break;
            
        }
    }
}
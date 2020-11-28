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
    int k=1;
    for(int i=0;i<n-1;++i){
        int min=a[i];
        int ind=i;
        for(int j=i+1;j<n;++j){
            if(min>a[j]){
                min=a[j];
                ind=j;
            }
        }
        
            swap(a[i],a[ind]);
            print(k,n,a);
            k++;
        
    }
}
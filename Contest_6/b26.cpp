#include<iostream>

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
        for(int j=i+1;j<n;++j){
            if(a[j]<a[i]){
                swap(a[i],a[j]);
            }
        }
        print(k,n,a);
        k++;
        
    }
}
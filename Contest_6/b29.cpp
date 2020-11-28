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
    bool sw=false;
    int k=1;
    do
    {
        sw=false;
        for(int i=1;i<n;++i){
            if(a[i-1]>a[i]){
                swap(a[i-1],a[i]);
                sw=true;
            }
        }
        if(sw){
            print(k,n,a);
            k++;
        }
    } while (sw);
     
}
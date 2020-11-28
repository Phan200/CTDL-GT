#include<iostream>
#include<algorithm>

using namespace std;

void Sort(int a[],int n){
    int max_index=0;
    for(int i=0;i<n-1;++i){
        max_index=i;
        for(int j=i+1;j<n;++j){
            if(a[j]>a[max_index]){
                max_index=j;
            }
        }
        swap(a[i],a[max_index]);
    }
    for(int i=0,j=n-1;i<=j;++i,--j){
        if(i==j) cout<<a[i]<<" ";
        else cout<<a[i]<<" "<<a[j]<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        Sort(a,n);
    }
    
}
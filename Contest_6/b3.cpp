#include<iostream>
#define ll long long int
using namespace std;

void Sort(int a[],int n){
    int m;
    int c=0;
    for(int i=0;i<n-1;++i){
        m=i;
        for(int j=i+1;j<n;++j){
            if(a[j]<a[m]){
                m=j;
            }
        }
        if(m!=i){
            swap(a[m],a[i]);
            ++c;
        }
    }
    cout<<c<<endl;
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